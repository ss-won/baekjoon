//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 02/05/2020.
//  Copyright © 2020 sowon. All rights reserved.
//

#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,-1,1};
char Map[1002][1002];
bool visited[1002][1002];
int sec = 0;
pair<int,int> sang;

int main(){
    int tc = 0;
    cin>>tc;
    
    while(tc--){
        /* 초 기 화 */

        int w,h = 0;
        sec = 0;
        memset(Map,'g',sizeof(Map));
        memset(visited,false,sizeof(visited));
        queue<pair<int,int>> sq;
        queue<pair<int,int>> fq;
        vector<pair<int,int>> fire;
        bool isover = false;
        
        /* 입 력 받 기 */
        cin>>w>>h;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>Map[i][j];
                if(Map[i][j]=='@'){
                    sang.first=i;
                    sang.second=j;
                }
                if(Map[i][j]=='*'){
                    fire.push_back(make_pair(i,j));
                }
            }
        }
        
        int sx,sy,fx,fy;
        /* 초 기 값 할 당 */
        sq.push(make_pair(sang.first,sang.second));
        visited[sang.first][sang.second]=true;
               
        for(int i=0;i<fire.size();i++){
            tie(fx,fy) = fire[i];
            fq.push(make_pair(fx, fy));
        }
       
        /*sang-gun moving*/
        while(!sq.empty()&&!isover){
            sec++;
            
            /*fire moving*/
            if(!fq.empty()){
              size_t size = fq.size();
              for(int i=0;i<size;i++){
                  tie(fx,fy) = fq.front();
                  fq.pop();
                  for(int j=0;j<4;j++){
                      int nfx = fx+mx[j];
                      int nfy = fy+my[j];
                      //cout<<"fire: ("<<nfx<<","<<nfy<<")"<<endl;
                      if(Map[nfx][nfy]=='.'||Map[nfx][nfy]=='@'){
                          Map[nfx][nfy] ='*';
                          //cout<<"make fire: ("<<nfx<<","<<nfy<<")"<<endl;
                          fq.push(make_pair(nfx, nfy));
                      }
                  }
              }
            }
            
            //cout<<"levelsize: "<<sq.size()<<endl;
            size_t size = sq.size();
            for(int i=0;i<size;i++){
                tie(sx,sy) = sq.front();
                sq.pop();
            for(int i=0;i<4;i++){
                int nsx = sx+mx[i];
                int nsy = sy+my[i];
                //cout<<"\n ("<<nsx<<","<<nsy<<")"<<endl;
                if(Map[nsx][nsy]=='g'){
                    isover = true;
                    break;
                }
                else if(Map[nsx][nsy]=='.'){
                    if(!visited[nsx][nsy]){
                        visited[nsx][nsy] = true;
                        sq.push(make_pair(nsx,nsy));
                        //cout<<"\npush("<<nsx<<","<<nsy<<")";
                    }
                }
            }
                if(isover) break;
        }
    }
        
        if(!isover){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<sec<<endl;
        }
    }
    return 0;
}