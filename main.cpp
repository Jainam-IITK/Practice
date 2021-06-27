#include <iostream>
#include <vector>
using namespace std;
void print_vec(vector<int> v){
    for (int c:v) {
        cout<<c<<' ';
    }
}
void print_grid(vector<vector<int>> &grid){
  cout<<endl;
    for ( auto v:grid) {
        for(int c:v){
          cout<<c<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<vector<int>> vec_to_grid(vector<vector<int>> &grid,int c,int r,vector<int> &v){
    int n = grid[0].size()-2*c;
    int m = grid.size()-2*r;

    int curr_m = m,curr_n = n;
    int len = 2*(curr_m+curr_n)-4;
    int counter = 0;
    int row = r,column = c;
    for(row=row;row-r<curr_m;row++,counter++) grid[row][column] = v[counter];
    row--;column++;
    for(column=column;column-c<curr_n;column++,counter++)grid[row][column] = v[counter];
    column--;row--;
    for(row=row;row>= r;row--,counter++)grid[row][column] = v[counter];
    row++;column--;
    for(column=column;column>c;column--,counter++)grid[row][column] = v[counter];
  
    return grid;
}
vector<int> cycle(vector<int> &v,int k){
  int size = v.size();
  vector<int> vv(size);
  for(int i = 0; i< size;i++){
     vv[(i+k)%size] = v[i];
  }
  return vv;
}

vector<vector<int>> grid_to_vec(vector<vector<int>> &grid,int k){
int n = grid[0].size();
    int m = grid.size();
  int c =0,r = 0;
  while(c<=n/2 and r<= m/2 ){
    int curr_m = m-2*r,curr_n = n-2*c;
    

    int counter = 0;
    vector<int> v(2*(curr_m+curr_n)-4);
    int row = r,column = c;

    for(row=row;row-r<curr_m;row++,counter++)v[counter] = grid[row][column];
    row--;column++;
    for(column=column;column-c<curr_n;column++,counter++)v[counter] = grid[row][column];
    column--;row--;
    for(row=row;row>= r;row--,counter++)v[counter] = grid[row][column];
    row++;column--;
    for(column=column;column>=c;column--,counter++)v[counter] = grid[row][column];
    
    v = cycle(v, k);
    grid = vec_to_grid(grid, c, r, c);

    c++;r++;
  }

  return grid;
    
}



int main(){
    vector<vector<int>> grid = {{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}};
    vector<int> sol = grid_to_vec(grid,0,0);
    print_vec(sol);
    cout<<endl;
    sol = cycle(sol,2+sol.size());
    print_vec(sol);
    grid = vec_to_grid(grid, 0, 0, sol);
    cout<<endl;
    print_grid(grid);
    //cout<<s.find(part)<<endl;

    return 0;
}
