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
        unordered_map<int,int>mp;
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id]=i;
        }
        queue<int>q;
        q.push(mp[id]);
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