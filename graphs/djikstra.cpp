//Djikstra algorithm	

set<pair<int,int>> s; //creating a set of pairs {distance from the source, node}
        vector<int> dist(n+1, INF); //distance array which gives the shortest path from source to that node. Initially, everything is at the distance of INF 
        dist[src] = 0; //distance of source node from source is obviously 0 xD
        s.insert({0,src}); //pushing in the source into the set
        while(!s.empty()){ //keep iterating until the set becomes empty
            pair<int,int> cur = *(s.begin()); //we store the element to be processed (current node)
            s.erase(s.begin());		      //and pop it out of the set/priority queue
	    int u_d = cur.first;		      //d stores the distance between cur_node and source
            int u = cur.second;	  	      //u is the current node
            for(auto v : adj[u]){             //we iterate over the connected nodes/children of the current node -> u
                //v -> gives a pair -> {child_node, weight/distance between parent and child node}
                int newdist = v.second + u_d; //new dist -> distance from source to parent + distance from parent to child
                int child_node = v.first;     
                if(newdist < dist[child_node]){ //if we have found a better distance, then we update it and push the node into the queue so that we can update it's children as well
                    dist[child_node] = newdist;
                    s.insert({dist[child_node], v.first});
                }
            }
        }
