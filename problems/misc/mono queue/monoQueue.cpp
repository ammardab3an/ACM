struct monoQueue{
    
    stack<pii> s1, s2;
    
    int size(){
        return s1.size() + s2.size();
    }    
    
    int empty(){
        return !size();
    }
    
    void clear(){
        while(!empty()) pop();
    }
    
    int get_gcd(){
        
        if(empty()){
            return 0;
        }
        if(!s1.empty() && !s2.empty()){
            return __gcd(s1.top().second, s2.top().second);
        }
        if(!s2.empty()){
            return s2.top().second;
        }
        return s1.top().second;
    }
    
    void push(int val){
        
        if(s2.empty()){
            s2.push({val, val});
        }
        else{
            s2.push({val, __gcd(s2.top().second, val)});
        }
    }
    
    void pop(){
        
        if(s1.empty()){
            while(!s2.empty()){
                
                if(s1.empty()){
                    s1.push({s2.top().first, s2.top().first});
                }
                else{
                    s1.push({s2.top().first, __gcd(s2.top().first, s1.top().second)});
                }
                
                s2.pop();
            }
        }
        assert(!s1.empty());
        s1.pop();
    }
};