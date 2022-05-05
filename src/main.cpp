#include<iostream>
#include<string>

#include<time.h>
#include <sstream>

using namespace std;


void unsortedGrdbk(int arr[166][6]);
int findingOC(int &x, int &y,int &z);
void sorting(int arr[166][6]);
void print(int arr[166][6],string arrayOfNames[30],string arrayOfLastnames[20]);
void printSorted(int arr[166][6],string arrayOfNames[30],string arrayOfLastnames[20]);
string finalOC(int &x, int &y,int &z);
float averageOC(int arr[166][6]);
bool passedExam(int arr[166][6],int i);


int main(){

    int arr[166][6];

    string arrayOfNames[30]={
        "Kiara", "Jaylin", "Emma", "Shyanne", "Kiana", "Zariah", "Jon", "Ivan",
        "Yesenia", "Nathanial", "Roman", "Melvin", "Kody", "Miracle", "Taryn",
        "Jalen", "Isabelle", "Sebastian", "Aurora", "Yamilet", "Braelyn", "Henry",
        "Laura", "Julien", "Valentina", "Lorelei", "Zaire", "Sofia", "Gregory", "Taylor"
    };
    string arrayOfLastnames[20]={
        "Obrien", "Le", "Boyle", "Golden", "Reese", "Lamb",
        "Guerra", "Conley", "Peterson", "Calhoun", "Dorsey",
        "Downs", "Walsh", "Rice", "Mayer", "White", "Ritter",
        "Robinson", "Conner", "Jefferson"
    };


    unsortedGrdbk(arr);

    print(arr, arrayOfNames, arrayOfLastnames);

    sorting(arr);

    printSorted(arr,arrayOfNames,arrayOfLastnames);

    cout<<"The average of final assessments is  "<<averageOC(arr)<<endl;



    return 0;


}




void unsortedGrdbk(int arr[166][6]){

    srand(time(nullptr));

    for(int c=0;c<166;c++){

        arr[c][0]=rand()%30;
        arr[c][1]=rand()%20;
        arr[c][2]=rand()%101;
        arr[c][3]=rand()%101;
        arr[c][4]=rand()%101;
        arr[c][5]=findingOC(arr[c][2],arr[c][3],arr[c][4]);


    }

}

int findingOC(int &x, int &y,int &z){

    int OC= (((x+y+z)/30)+1);
    return OC;

}

void sorting(int arr[166][6]){


    int temp;

    for(int i=0;i<166;i++){

        for(int j=i+1;j<166;j++){

            if(arr[i][5]<arr[j][5]){

                //it swaps only the fifth position, i have to swap the whole row

                for (int c = 0; c < 6; c++){

                    temp=arr[i][c];
                    arr[i][c]=arr[j][c];
                    arr[j][c]=temp;

                }
            }
        }
    }
}

void print(int arr[166][6],string arrayOfNames[30],string arrayOfLastnames[20]){


      for(int nc=0;nc<166;nc++){

        cout<<
               nc+1<<"."        <<"  "
            <<arrayOfNames[arr[nc][0]]
           <<" "
          <<arrayOfLastnames[arr[nc][1]]
         <<"  "<<
           arr[nc][2]    <<"  "<<
           arr[nc][3]    <<"  "<<
           arr[nc][4]    <<"  "<<
           arr[nc][5]<<endl<<endl;

            }

            }

void printSorted(int arr[166][6],string arrayOfNames[30],string arrayOfLastnames[20]){
    
    for(int nc=0;nc<166;nc++){

        cout<<
               nc+1<<"."        <<"  "
            <<arrayOfNames[arr[nc][0]]
                <<" "
               <<arrayOfLastnames[arr[nc][1]]
                <<"  "<<
                  arr[nc][2]    <<"  "<<
                  arr[nc][3]    <<"  "<<
                  arr[nc][4]    <<"  "<<

                  finalOC(arr[nc][3],arr[nc][4],arr[nc][5])<<endl<<endl;

    }

}

string finalOC(int &x, int &y,int &z){

    if(x>49 && y>49){

        stringstream ss;
        ss << z;
        string str = ss.str();

        return str;

    }


    else if(x<50 && y<50){
        return "RV, VI";
    }


    else if(x<50){

        return "RV";
    }
    else if(y<50){


        return "VI";

    }

}

float averageOC(int arr[166][6]){

    float sum=0;
    int passes=0;
    for(int i=0;i<166;i++){

        if(passedExam(arr,i)){

            passes++;
            sum+=arr[i][5];
        }

    }

    return sum/passes;

}

bool passedExam(int arr[166][6],int i){


    if(arr[i][3]>49 && arr[i][4]>49){

        return true;

    }
}
