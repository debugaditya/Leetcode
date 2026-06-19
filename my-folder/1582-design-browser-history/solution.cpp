class BrowserHistory {
public:
    struct node{
        node* next=nullptr;
        node* prev=nullptr;
        string link="";
    };
    node* v = new node();
    BrowserHistory(string homepage) {
        v->link=homepage;
    }
    
    void visit(string url) {
        node* n=new node();
        n->link=url;
        v->next=n;
        n->prev=v;
        v=n;
    }
    
    string back(int steps) {
        while(steps>0&&v->prev){
            steps--;
            v=v->prev;
        }
        return v->link;
    }
    
    string forward(int steps) {
        while(steps>0&&v->next){
            steps--;
            v=v->next;
        }
        return v->link;
    }
};

