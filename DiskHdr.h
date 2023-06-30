#include<iostream>
#include<climits>
using namespace std;
class node
{
        public:
                node(int,int,node*);
                int number;
                int value;
                node* next;
                friend class SSTF;
};

class SSTF
{
        public:
                SSTF();
                void display(int[]);
                int compare(node *,node *);
                void getdetails();
                void findheadmovement(int [],int,int);
                void headmovementofFCFS(int[],int,int);
                void headmovementofSCAN(int[],int,int,char,int);
                void headmovementofCSCAN(int[],int,int,char,int);
                void headmovementofLOOK(int[],int,int,char,int);
                void headmovementofCLOOK(int[],int,int,char,int);
                void sort(int[],int);
                void insert(node*);
                bool found(int[],int);
                void insert1(node*);
                int find_max(int*);
                int minimum(node*);
                node *first;
                node *first1;
                int *arr;
                int tracks;
                int num_req;
                int head;
};
