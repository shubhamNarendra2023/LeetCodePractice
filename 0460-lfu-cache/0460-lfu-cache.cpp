
class Node {
public:
    int data;
    int occur;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->occur = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> address;
    unordered_map<int, int> map;
    unordered_map<int, pair<Node*, Node*>> freq;

    /*
    here the map freq actually stores three things 
    the key and then a pair that stores head and tail 
    freq[n].first is actually head and 
    freq[n].second is actually the tail 
    for any n belonging to frequencies used 

    the adress map links key to the nodes address 
    and address can be found of any node 
    */

    int maxSizeCache; // stores the capacity 
    int minFreq;      // stores the minimum frequency at that perticular time
    int curSize;      // stores the size at that perticular time

    /* FUNCTION TO UPDATE THE FREQUENCY MAP ACCORDINGLY */

    void update(Node* node) {
      
        int freqKey = node->occur;        // stores the frequency of the perticular node
        auto& freqList = freq[freqKey];   // pair of head and tail for perticular freq[n]

      //STEP 1 : deleting the node 

               // case 1 : if there exists only one node in entire linked list 
               //          at that perticular frequency 
               if (node == freqList.first && node == freqList.second) 
               {
                     freq.erase(freqKey);
                     if (minFreq == freqKey) 
                     {
                        minFreq++;
                     }
               } 


               // case 2 : if the exists node in head position in the linked list 
               //          head pointer needs to be updated
               else if (node == freqList.first) 
               {
                     freqList.first = node->next;
                     freqList.first->prev = nullptr;
               } 

               // case 3 : if the exists node in tail position in the linked list 
               //          tail pointer needs to be updated
               else if (node == freqList.second) 
               {
                     freqList.second = node->prev;
                     freqList.second->next = nullptr;
               } 

               // case 4 : exists somewhere in the midile of linked list  
               //          no pointer needs to beupdated just node needs to be removed       
               else 
               {
                     node->prev->next = node->next;
                     node->next->prev = node->prev;
               }

        // STEP 2 : updating the occurance of the node 
        node->occur++;

        // STEP # : inserting the node 

               // check wether the list for perticular frequency exists or not 

               //if it exists then simply add to tail 
               if (freq.find(freqKey + 1) != freq.end()) 
               {
                     auto& nextFreqList = freq[freqKey + 1];
                     nextFreqList.second->next = node;
                     node->prev = nextFreqList.second;
                     nextFreqList.second = node;
               } 

               //else create a linked list and add to the freq[n]
               else 
               {
                     auto add = make_pair(node, node);
                     freq[freqKey + 1] = add;
               }
    }

public:

   // constructor intiallization 
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 1;
        curSize = 0;
    }

    int get(int key) 
    {
        // update the frequency map and return the value of key 
        if (map.find(key) != map.end()) {update(address[key]);  return map[key]; } 
        // in any othe case retuen -1 
        else return -1;     
    }

    void put(int key, int value) 
    {
        // exceptional case of 0 size 
        if (maxSizeCache == 0) return;

        //case 1 : key already exists then change the value and update the map 
        if (map.find(key) != map.end()) {map[key] = value; update(address[key]);} 
        
        //case 2 : new addition 
        else 
        {
            // performing deletion if size oveloads the capacity 

            if (curSize >= maxSizeCache)
             {
                
                auto& minFreqList = freq[minFreq]; //storing head - tail pairs 

                int keyToRemove = minFreqList.first->data; // the key value needed to remove 

                map.erase(keyToRemove); //erasing from th map (key , value) 

                address.erase(keyToRemove); //erasing address

                //case if nothing exists after deletion in that freq[n]
                if (minFreqList.first == minFreqList.second) freq.erase(minFreq);
                
                // else update tail pointer normal way 
                else 
                {
                    minFreqList.first = minFreqList.first->next;
                    minFreqList.first->prev = nullptr;
                }

                curSize--; // regulate size 
             }


             // inserting a new element 
            map[key] = value;   // creating (key , value) pair 
            minFreq = 1;

            // creation of entirely new node 
            Node* newNode = new Node(key);
            address[key] = newNode;

            // if in freq [1] there already exists an 
            // linked list simple connect newnode and 
            // then update tail pointer

            if (freq.find(1) != freq.end()) 
            {
                auto& firstFreqList = freq[1];
                firstFreqList.second->next = newNode;
                newNode->prev = firstFreqList.second;
                firstFreqList.second = newNode;
            } 
           
            // if no element exists in freq[1]
            // then push a linked list in freq[1]  
            else 
            {
                auto add = make_pair(newNode, newNode);
                freq[1] = add;
            }

            curSize++; // incrementing for addition of an element 
        }
    }
};