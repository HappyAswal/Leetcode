class Solution {
public:
    string arrangeWords(string text) {
        //string size pos
        text[0]=tolower(text[0]);
        vector<tuple<string,int,int>>ssize;
        string temp="";
        int pos=1;
        int size=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                ssize.push_back({temp,size,pos});
                temp="";
                size=0;
                pos++;
            }else{
                temp+=text[i];
                size++;
            }
        }
        ssize.push_back({temp,size,pos});
        //custom sort
        sort(ssize.begin(),ssize.end(),[](auto &a,auto &b){
            if(get<1>(a)==get<1>(b)) return get<2>(a)<get<2>(b);
            else return get<1>(a)<get<1>(b);
        });
        //ANSWER
        string ans="";
        for(auto[s,sz,p]:ssize){
            ans+=s+" ";
        }
        //remove extra space
        ans.pop_back();
        ans[0]=toupper(ans[0]);
        return ans;
    }
};