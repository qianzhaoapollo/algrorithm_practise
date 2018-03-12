#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct csvdata {
    string date;
    string road_id;
    string long_late;
    string longtitude;
    string latetitude;
    int len;
    int total_flow;
    int trunk_flow;
    int car_flow;
};

struct cmp {
    bool operator()(csvdata a, csvdata b) {
        return a.total_flow < b.total_flow;
    }
};

priority_queue<csvdata, vector<csvdata>, cmp> Q;

int main()
{
    string filename;
    ifstream infilename("inputfilename.txt");
    getline(infilename, filename);

    string value;
    ifstream infile(filename.c_str());
    ofstream out;
    while(infile.good()) {
        getline(infile, value);

        string tmp_total;
        string tmp_trunk;
        string tmp_car;

        csvdata intp;

        int i=0;
        int count = 0;
        int count_pos = 0;
        while(value[i] != '\0') {
            if(value[i] == '|') {
                count++;
                i++;
            }
            if(value[i] == ';') {
                count_pos++;
                i++;
            }
            if(count == 0)
                intp.date += value[i];
            if(count == 1)
                intp.road_id += value[i];
            if(count == 2) {
                if(count_pos == 0)
                    intp.longtitude += value[i];
                if(count_pos == 1)
                    intp.latetitude += value[i];
            }

            if(count == 3)
                tmp_total += value[i];
            if(count == 4)
                tmp_trunk += value[i];
            if(count == 5)
                tmp_car += value[i];

            intp.total_flow = atoi(tmp_total.c_str());
            intp.trunk_flow = atoi(tmp_trunk.c_str());
            intp.car_flow = atoi(tmp_car.c_str());

            i++;
        }

        Q.push(intp);
        //cout<<intp.date<<" "<< intp.road_id <<" "<< intp.long_late <<" "<< intp.total_flow <<" "<< intp.trunk_flow <<" "<< intp.car_flow <<endl;

    }
    cout<<"Q.size(): "<<Q.size()<<endl;
    int num=0;

    while(!Q.empty()) {
        cout<<Q.top().longtitude<<" "<<Q.top().latetitude<<endl;

        Q.pop();
        num++;
    }

    cout<<"num: "<<num;

    return 0;
}


























