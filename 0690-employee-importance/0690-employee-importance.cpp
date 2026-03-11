/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int index;
        unordered_map<int,int>mp;
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id]=i;
        }
        index=mp[id];
        queue<int>q;
        q.push(index);
        int imp=0;
        while(!q.empty()){
            int w=q.front(); q.pop();
            imp+=employees[w]->importance;
            for(int nbr:employees[w]->subordinates){
                q.push(mp[nbr]);
            }
        }
        return imp;
    }
};