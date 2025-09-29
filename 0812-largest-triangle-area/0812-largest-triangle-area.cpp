class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        //|x₁(y₂ - y₃) + x₂(y₃ - y₁) + x₃(y₁ - y₂)| / 2
        double marea=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double area=abs(
                        points[i][0]*(points[j][1]-points[k][1])+
                        points[j][0]*(points[k][1]-points[i][1])+
                        points[k][0]*(points[i][1]-points[j][1])
                    )/2.0;
                    marea=max(marea,area);    
                }
            }
        }
        return marea;
            
    }
};