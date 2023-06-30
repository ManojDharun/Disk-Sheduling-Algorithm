#include"ex12Hdr.h"
int main()
{
        SSTF obj;
        int ch;
        do{
        cout<<"ENTER YOUR CHOICE :"<<endl<<endl;
        cout<<"1 -> SSTF ALGORIHTM"<<endl;
        cout<<"2 -> FCFS ALGORITHM"<<endl;
        cout<<"3 -> SCAN ALGORIHTM"<<endl;
        cout<<"4 -> CSCAN ALGORITHM"<<endl;
        cout<<"5 -> LOOK ALGORITHM"<<endl;
        cout<<"6 -> CLOOK ALGORITHM"<<endl;
        cin>>ch;
        if(ch==1){
                obj.getdetails();
                cout<<"SSTF ALGORITHM"<<endl<<endl;
                obj.findheadmovement(obj.arr,obj.head,obj.num_req);
                cout<<endl;
        }
        else if(ch==2){
                obj.getdetails();
                cout<<"FCFS ALGORITHM"<<endl<<endl;
                obj.headmovementofFCFS(obj.arr,obj.head,obj.num_req);
        }
        else if(ch==3)
        {
                obj.getdetails();
                cout<<"SCAN ALGORITHM :"<<endl<<endl;
                cout<<"ENTER THE DIRECTION :"<<endl;
                char ch;
                cin>>ch;
                obj.headmovementofSCAN(obj.arr,obj.head,obj.num_req,ch,obj.tracks);
        }
        else if(ch == 4){
                obj.getdetails();
                cout<<endl<<"CSCAN ALGORITHM :"<<endl<<endl;
                cout<<"ENTER THE DIRECTION :"<<endl;
                char chr;
                cin>>chr;
                obj.headmovementofCSCAN(obj.arr,obj.head,obj.num_req,chr,obj.tracks);
        }
        else if(ch==5){
                obj.getdetails();
                cout<<endl<<"LOOK ALGORITHM :"<<endl<<endl;
                cout<<"ENTER THE DIRECTION :"<<endl;
                char chr1;
                cin>>chr1;
                obj.headmovementofLOOK(obj.arr,obj.head,obj.num_req,chr1,obj.tracks);
        }
        else if(ch == 6){
                obj.getdetails();
                cout<<endl<<"CLOOK ALGORITHM :"<<endl<<endl;
                cout<<"ENTER THE DIRECTION :"<<endl;
                char chr2;
                cin>>chr2;
                obj.headmovementofCLOOK(obj.arr,obj.head,obj.num_req,chr2,obj.tracks);
        }
        }while(ch!=0);
        return 0;
}
