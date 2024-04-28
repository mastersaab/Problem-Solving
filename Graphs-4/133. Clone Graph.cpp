 Node* dfs(Node*node,unordered_map<Node*,Node*>&map){
        // nyi node ke adj neighbours ke liye en vector bna lo
        vector<Node*>nyineighbour;
        // jo bhi node aaye uski copy bna lo aur map me store kr lo
        Node* clone=new Node(node->val);
        map[node]=clone;
        // ab node ke neighbour pe jake dekho store hai ki nhi map me
        for(auto it:node->neighbors){
            // agar map me us index pe hai tab map se val utha lo
            if(map.find(it)!=map.end()){
                nyineighbour.push_back(map[it]);
            }
            // nahi to dfs call chla do neighbour ke liye
            else{
                nyineighbour.push_back(dfs(it,map));
            }
        }
        // dfs call pura hone pr sari val nyineighbour me store hnn ab use copy kr lo clone ke neighbor me
        clone->neighbors=nyineighbour;
        return clone;

    }
    Node* cloneGraph(Node* node) {
        // map me phla Node* -> purana node
        // map me dusra Node* -> naya node
        unordered_map<Node*,Node*>map;
        // agar zero node hai to 
        if(node==NULL) return NULL;
        // agar ek node hai to adj list ki size zero hogi clone bna ke node ka return kr do
        if(node->neighbors.size()==0){
            Node* newNode=new Node(node->val);
            return newNode;
        }
        // dfs traversal for rest of the nodes
        return dfs(node,map);
    }
