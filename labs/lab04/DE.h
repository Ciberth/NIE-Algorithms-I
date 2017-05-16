
template<class T>
void Binboom<T>::DEbezoek(function<void(T&&)>preorder,
                           function<void(T&&)>inorder,
                           function<void(T&&)>postorder){
    stack<pair<Binknoop<T> *,int > >ATW;//ATW: Af Te Werken
    if ((*this)!=0){
        ATW.emplace((*this).get(),1);
        while (!ATW.empty()){
            Binknoop<T> * nuknoop=ATW.top().first;
            int pass=ATW.top().second;
            ATW.top().second++;
            switch (pass){
                case 1:
                    preorder(move(nuknoop->sl));
                    if (nuknoop->links)
                        ATW.emplace(nuknoop->links.get(),1);
                    break;
                case 2:
                    inorder(move(nuknoop->sl));
                    if (nuknoop->rechts)
                        ATW.emplace(nuknoop->rechts.get(),1);
                    break;
                case 3:
                    postorder(move(nuknoop->sl));
                    ATW.pop();
            }
        };
    };
};

