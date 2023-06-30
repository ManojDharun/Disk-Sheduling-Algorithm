#include"ex12Hdr.h"

node::node(int num,int val,node *n)
{
        number = num;
        value = val;
        next = n;
}

SSTF::SSTF()
{
        first = NULL;
        first1 = NULL;
        arr = new int[10];
}

int SSTF::compare(node *arr,node *arr1)
{
        int mini = minimum(arr);
        int mini1 = minimum(arr1);
        int res1,res2,res3,res4;
        node *temp = first;
        while(temp!=NULL)
        {
                if(temp -> number == mini)
                {
                        res1 = temp -> number;
                        res3 = temp -> value;
                }
                temp = temp -> next;
        }
        temp = first1;
        while(temp!=NULL)
        {
                if(temp -> number == mini1)
                {
                        res2 = temp -> number;
                        res4 = temp -> value;
                }
                temp = temp -> next;
        }
        if(res1 < 0)
                return res2;
        else if(res2 < 0)
                return res1;
        else if(res3 > res4)
        {
                return res2;
        }
        else if(res3 < res4)
        {
                return res1;
        }
        else
                return -1;
}

void SSTF::getdetails()
{
        cout<<"ENTER THE DISK TRACKS :"<<endl;
        cin>>tracks;
        cout<<"ENTER THE NUMBER OF REQUEST : "<<endl;
        cin>>num_req;
        arr = new int[num_req];
        cout<<"ENTER THE REQUETS QUEUE : "<<endl;
        int i;
        for(i=0;i<num_req;i++)
        {
                cin>>arr[i];
                if(arr[i] > tracks){
                        cout<<"YOUR REQUEST SHOULD BE WITHIN THE TRACKS :"<<endl;
                        i = i-1;
                }
        }
        cout<<"CURRENT POSITION OF READ/WRITE HEAD : "<<endl;
        cin>>head;
}

void SSTF::findheadmovement(int arr[],int head,int num_req)
{
        int out = head;
        int i,j;
        int temp_array[10];
        for(i=0;i<num_req;i++)
        {
                for(j=0;j<num_req;j++)
                {
                        bool test = found(temp_array,arr[j]);
                        if(out > arr[j] and test == false)
                        {
                                int temp = out - arr[j];
                                node *newnode1 = new node(arr[j],temp,NULL);
                                insert(newnode1);
                        }
                        else if(out < arr[j] and test == false){
                                int temp = arr[j] - out;
                                node *newnode2 = new node(arr[j],temp,NULL);
                                insert1(newnode2);
                        }
                }
                if(out != head){
                        temp_array[i] = out;
                }
                else if(out == head)
                {
                        temp_array[i] = head;
                }
                int max = find_max(arr);
                if(i == num_req - 1)
                {
                        temp_array[i+1] = max;
                        display(temp_array);
                }
                int min_value = compare(first,first1);
                out = min_value;
                first = NULL;
                first1 = NULL;
        }
}

int SSTF::find_max(int *arr)
{
        int max = arr[0];
        int i;
        for(i=0;i<num_req;i++)
        {
                if(max < arr[i])
                {
                        max = arr[i];
                }
        }
        return max;
}

bool SSTF::found(int arr[],int res)
{
        int i;
        for(i=0;i<10;i++)
        {
                if(res == arr[i])
                {
                        return true;
                }
        }
        return false;
}

void SSTF::insert1(node *newnode)
{
        if(first1 == NULL)
        {
                first1 = newnode;
        }
        else{
                node* temp = first1;
                while(temp -> next != NULL)
                {
                        temp = temp -> next;
                }
                temp->next = newnode;
        }
}

void SSTF::insert(node *newnode)
{
        if(first == NULL)
        {
                first = newnode;
        }
        else{
                node *temp = first;
                while(temp -> next != NULL)
                {
                        temp = temp -> next;
                }
                temp->next = newnode;
        }
}


int SSTF::minimum(node *head)
{
           int min = 99999,res;
           // Check loop while head not equal to NULL
           while (head != NULL) {

           // If min is greater then head->value then
           // assign value of head->value to min
           // otherwise node point to next node.
                   if (min > head->value)
                                res = head -> number;
                                min = head -> value;
                   head = head->next;
           }
           return res;
}

void SSTF::display(int temp_array[])
{
        int i,track_mov = 0;
                //initialize to zero
        cout<<endl<<endl;
        cout<<"SEQUENCE TRACK MOVEMENTS :"<<endl;
        for(i=0;i<num_req+1;i++)
        {
                cout<<temp_array[i]<<"  "<<endl<<endl;
        }
        cout<<"TOTAL NUMBER OF TRACK MOVEMENT :"<<endl;
        i=0;
        while(i<num_req)
        {
                if(temp_array[i] > temp_array[i+1])
                        track_mov = track_mov + (temp_array[i] - temp_array[i+1]);
                else
                        track_mov = track_mov + (temp_array[i+1] - temp_array[i]);
                i++;
        }
        cout<<endl;
        cout<<"===="<<track_mov<<"==="<<endl;
}

void SSTF::headmovementofFCFS(int arr[],int head,int num_req)
{
        int seek_count = 0;
        int distance,cur_track;
        int i;
        for(i=0;i<num_req;i++)
        {
                cur_track = arr[i];
                distance = abs(cur_track - head);
                seek_count = seek_count + distance;
                head = cur_track;
        }
        cout<<endl;
        cout<<"FCFS DISK ALGORITHM :"<<endl<<endl;
        cout<<"TOTAL NUMBER OF SEEK OPERATIONS :"<<endl<<endl;
        cout<<seek_count<<endl<<endl;
        cout<<"SEEK SEQUENCE :"<<endl;
        for(i=0;i<num_req;i++)
        {
                cout<<arr[i]<<endl<<endl;
        }
}

void SSTF::headmovementofSCAN(int arr[],int head,int num_req,char c,int tracks)
{
        int i,j=0,k=0;
        int arr1[num_req],arr2[num_req];
        for(i=0;i<num_req;i++)
        {
                if(head > arr[i])
                {
                        arr1[j] = arr[i];
                        j++;
                }
                else if(head < arr[i])
                {
                        arr2[k] = arr[i];
                        k++;
                }
        }
        sort(arr1,j);
        sort(arr2,k);
        cout<<endl<<" SEEK SEQUENCE :"<<endl<<endl;
        if( c == 'R')
        {
                int track_mov = arr2[0] - head;
                int right = sizeof(arr2)/sizeof(arr2[0]);
                cout<<head<<endl<<endl;
                for(i=0;i<k;i++)
                {
                        if(i!=k-1)
                                track_mov = track_mov + (arr2[i+1] - arr2[i]);
                        cout<<arr2[i]<<endl<<endl;
                }
                track_mov = track_mov + ((tracks-1) - arr2[i-1]);
                cout<<tracks-1<<endl<<endl;
                int left = sizeof(arr1)/sizeof(arr1[0]);
                for(i=j-1;i>=0;i--)
                {
                        if(i!=0)
                                track_mov = track_mov + (arr1[i] - arr1[i-1]);
                        cout<<arr1[i]<<endl<<endl;
                }
                track_mov = track_mov + ((tracks - 1) - arr1[j-1]);
                cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
                cout<<track_mov<<endl;
        }
        else if( c == 'L')
        {
                int track_mov = head - arr1[j-1];
                cout<<head<<endl<<endl;
                int left = sizeof(arr1)/sizeof(arr1[0]);
                for(i=j-1;i>=0;i--)
                {
                        if(i!=0)
                                track_mov = track_mov + (arr1[i] - arr1[i-1]);
                        cout<<arr1[i]<<endl<<endl;
                }
                track_mov = track_mov + (arr1[i+1]);
                int right = sizeof(arr2)/sizeof(arr2[0]);
                track_mov = track_mov + (arr2[k-1]);
                int s = 0;
                cout<<s<<endl<<endl;
                for(i=0;i<k;i++)
                {
                        cout<<arr2[i]<<endl<<endl;
                }
                cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
                cout<<track_mov<<endl;
        }
}

void SSTF::sort(int arr[],int size)
{
        int i,j,temp;
        for(i=0;i<(size-1);i++)
        {
                for(j=0;j<(size-i-1);j++)
                {
                        if(arr[j] > arr[j+1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
        }
}

void SSTF::headmovementofCSCAN(int arr[],int head,int num_req,char c,int tracks)
{
       int i,j=0,k=0;
       int arr1[num_req],arr2[num_req];
       for(i=0;i<num_req;i++)
       {
               if(head > arr[i])
               {
                       arr1[j] = arr[i];
                       j++;
               }
              else if(head < arr[i])
              {
                       arr2[k] = arr[i];
                       k++;
              }
        }
        sort(arr1,j);
        sort(arr2,k);
        cout<<endl<<"SEEK SEQUENCE :"<<endl<<endl;
        if( c == 'R')
        {
                int track_mov = arr2[0] - head;
                int right = sizeof(arr2)/sizeof(arr2[0]);
                cout<<head<<endl<<endl;
                for(i=0;i<k;i++)
                {
                        if(i!=k-1)
                               track_mov = track_mov + (arr2[i+1] - arr2[i]);
                        cout<<arr2[i]<<endl<<endl;
                }
                track_mov = track_mov + ((tracks-1) - arr2[i-1]);
                cout<<tracks-1<<endl<<endl;
                int left = sizeof(arr1)/sizeof(arr1[0]);
                for(i=0;i<j;i++)
                {
                         if(i!=j-1)
                               track_mov = track_mov + (arr1[i+1] - arr1[i]);
                         cout<<arr1[i]<<endl<<endl;
                }
                track_mov = track_mov + ((tracks - 1) - arr1[0]);
                cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
                cout<<track_mov<<endl;
         }
         else if( c == 'L')
         {
                int track_mov = head - arr1[j-1];
                cout<<head<<endl<<endl;
                int left = sizeof(arr1)/sizeof(arr1[0]);
                for(i=j-1;i>=0;i--)
                {
                         if(i!=0)
                               track_mov = track_mov + (arr1[i] - arr1[i-1]);
                         cout<<arr1[i]<<endl<<endl;
                }
                track_mov = track_mov + (arr1[i+1]);
                int right = sizeof(arr2)/sizeof(arr2[0]);
                track_mov = track_mov + (arr2[k-1]);
                track_mov = track_mov + (arr2[k-1] - arr2[0]);
                int s = 0;
                cout<<s<<endl<<endl;
                for(i=k-1;i>=0;i--)
                {
                         cout<<arr2[i]<<endl<<endl;
                }
                cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
                cout<<track_mov<<endl;
         }
}


void SSTF::headmovementofLOOK(int arr[],int head,int num_req,char c,int tracks)
{
                int i,j=0,k=0;
                int arr1[num_req],arr2[num_req];
                for(i=0;i<num_req;i++)
                {
                       if(head > arr[i])
                       {
                              arr1[j] = arr[i];
                              j++;
                       }
                       else if(head < arr[i])
                       {
                              arr2[k] = arr[i];
                              k++;
                       }
            }
            sort(arr1,j);
            sort(arr2,k);
            cout<<endl<<" SEEK SEQUENCE :"<<endl<<endl;
            if( c == 'R')
            {
                     int track_mov = arr2[0] - head;
                     int right = sizeof(arr2)/sizeof(arr2[0]);
                     cout<<head<<endl<<endl;
                     for(i=0;i<k;i++)
                     {
                             if(i!=k-1)
                                    track_mov = track_mov + (arr2[i+1] - arr2[i]);
                             cout<<arr2[i]<<endl<<endl;
                     }
                     int left = sizeof(arr1)/sizeof(arr1[0]);
                     for(i=j-1;i>=0;i--)
                     {
                            if(i!=0)
                                  track_mov = track_mov + (arr1[i] - arr1[i-1]);
                            cout<<arr1[i]<<endl<<endl;
                     }
                     track_mov = track_mov + (arr2[k-1] - arr1[j-1]);
                     cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
                     cout<<track_mov<<endl;
            }
            else if( c == 'L')
            {
                     int track_mov = head - arr1[j-1];
                     cout<<head<<endl<<endl;
                     int left = sizeof(arr1)/sizeof(arr1[0]);
                     for(i=j-1;i>=0;i--)
                     {
                            if(i!=0)
                                  track_mov = track_mov + (arr1[i] - arr1[i-1]);
                            cout<<arr1[i]<<endl<<endl;
                     }
                     int right = sizeof(arr2)/sizeof(arr2[0]);
                     track_mov = track_mov + (arr2[k-1] - arr1[0]);
                     for(i=0;i<k;i++)
                     {
                            cout<<arr2[i]<<endl<<endl;
                     }
                     cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
                     cout<<track_mov<<endl;
            }
}

void SSTF::headmovementofCLOOK(int arr[],int head,int num_req,char c,int tracks)
{
       int i,j=0,k=0;
       int arr1[num_req],arr2[num_req];
       for(i=0;i<num_req;i++)
       {
             if(head > arr[i])
             {
                     arr1[j] = arr[i];
                     j++;
             }
             else if(head < arr[i])
             {
                     arr2[k] = arr[i];
                     k++;
             }
        }
        sort(arr1,j);
        sort(arr2,k);
        if( c == 'R')
        {
             int track_mov = arr2[0] - head;
             int right = sizeof(arr2)/sizeof(arr2[0]);
             cout<<head<<endl<<endl;
             for(i=0;i<k;i++)
             {
                     if(i!=k-1)
                             track_mov = track_mov + (arr2[i+1] - arr2[i]);
                             cout<<arr2[i]<<endl<<endl;
             }
             int left = sizeof(arr1)/sizeof(arr1[0]);
             for(i=0;i<j;i++)
             {
                     if(i!=j-1)
                             track_mov = track_mov + (arr1[i+1] - arr1[i]);
                             cout<<arr1[i]<<endl<<endl;
             }
             track_mov = track_mov + (arr2[k-1] - arr1[0]);
             cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
             cout<<track_mov<<endl;
        }
        else if( c == 'L')
        {
             int track_mov = head - arr1[j-1];
             cout<<head<<endl<<endl;
             int left = sizeof(arr1)/sizeof(arr1[0]);
             for(i=j-1;i>=0;i--)
             {
                     if(i!=0)
                           track_mov = track_mov + (arr1[i] - arr1[i-1]);
                           cout<<arr1[i]<<endl<<endl;
             }
             int right = sizeof(arr2)/sizeof(arr2[0]);
             track_mov = track_mov + (arr2[k-1] - arr1[0]);
             track_mov = track_mov + (arr2[k-1] - arr2[0]);
             for(i=k-1;i>=0;i--)
             {
                     cout<<arr2[i]<<endl<<endl;
             }
             cout<<endl<<"TOTAL SEEK OPERATION :"<<endl<<endl;
             cout<<track_mov<<endl;
        }
}
