#include<iostream>
using namespace std;

void outarr(char arr[3][3]){
    system("cls");
    cout<<arr[0][0]<<" | "<<arr[1][0]<<" | "<<arr[2][0]<<endl;
    cout<<"_________"<<endl;
    cout<<arr[0][1]<<" | "<<arr[1][1]<<" | "<<arr[2][1]<<endl;
    cout<<"_________"<<endl;
    cout<<arr[0][2]<<" | "<<arr[1][2]<<" | "<<arr[2][2]<<endl;
}

bool checkwin(char arr[3][3]){
    //horizontal
    if(arr[0][0]==arr[1][0] && arr[0][0]==arr[2][0]){
        return 1;
    }
    if(arr[0][1]==arr[1][1] && arr[0][1]==arr[2][1]){
        return 1;
    }
    if(arr[0][2]==arr[1][2] && arr[0][2]==arr[2][2]){
        return 1;
    }
    //vertical
     if(arr[0][0]==arr[0][1] && arr[0][0]==arr[0][2]){
        return 1;
    }
    if(arr[1][0]==arr[1][1] && arr[1][0]==arr[1][2]){
        return 1;
    }
    if(arr[2][0]==arr[2][1] && arr[2][0]==arr[2][2]){
        return 1;
    }
    //diagnals
    if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2]){
        return 1;
    }
    if(arr[2][0]==arr[1][1] && arr[2][0]==arr[0][2]){
        return 1;
    }
    return 0;
}

int tictactoe(char arr[3][3],char *addr[]){
    outarr(arr);
    int input;
    int count=0;
  while(!checkwin(arr) && count<9){
    if(count%2==0){
        cout<<" player 1 ----  ";
        cin>>input;
        *addr[input]='X';
        count++;
        outarr(arr);
    }
    else{
        cout<<" player 2 ----  ";
        cin>>input;
        *addr[input]='O';
        count++;
        outarr(arr);
    }
  }
  if(count>=9){
    return 0;
  }
  if(count%2==0){
    return 2;
  }
  return 1;



}

int main(){
    char *addr[9];
    char arr[3][3];
    int pos=1;
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            arr[j][i]=48+pos;
            char *ptr= &arr[j][i];
            addr[pos]=ptr;
            pos++;
        }
    }
    cout<<"welcome to tic-tac-toe"<<endl<<endl;
    cout<<"player 1 is 'X' and player 2 is 'O'      To play the game enter 'S' "<<endl;
    char dum;
    cin>>dum;
    system("cls");
    int res=tictactoe(arr,addr);
    if(res==1){
        cout<<"player 1 wins"<<endl;
    }
    else if(res==2){
        cout<<"player 2 wins"<<endl;
    }
    else{
        cout<<"draw"<<endl;
    }
    cout<<"to play again enter 'A' "<<endl;
    char a;
    cin>>a;
    return 0;
}