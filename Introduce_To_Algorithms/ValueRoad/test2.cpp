#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

struct csvdata {
    string date;
    string road_id;
    string long_late;
    string start_point;
    string end_point;
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
priority_queue<csvdata, vector<csvdata>, cmp> R;

int main()
{
    string filename;
    ifstream infilename("inputfilename.txt");
    ofstream fout("out.csv");
    getline(infilename, filename);

    string value;
    ifstream infile(filename.c_str());
    ofstream out;
    while(!infile.eof()) {
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
                intp.long_late += value[i];
                if(count_pos == 0)
                    intp.start_point += value[i];
                if(count_pos == 1)
                    intp.end_point += value[i];
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
        if(intp.long_late.empty())
            continue;

        Q.push(intp);
        //cout<<intp.date<<" "<< intp.road_id <<" "<< intp.long_late <<" "<< intp.total_flow <<" "<< intp.trunk_flow <<" "<< intp.car_flow <<endl;

    }
    cout<<"Q.size(): "<<Q.size()<<endl;
    int length = Q.size();
    R = Q;cout<<R.size()<<endl;

    int num=0;
    int countnull=0;

    list<csvdata> full_road;
    list<csvdata> swap_place;

    int sameflowcount=0;
    int sametotalflow=0;
    //int sametrunkflow=0;
    int diffflag = 0;
    queue<int> total_flow;
    queue<int> total_flow_copy;
    while(!Q.empty()) {
        //cout<<Q.top().start_point<<" "<<Q.top().end_point<<" "<<Q.top().total_flow<<endl;
        //cout<<Q.top().long_late<<" "<<Q.top().total_flow<<endl;
        if(Q.top().long_late.empty())
            countnull++;

        num++;

        if(sametotalflow != Q.top().total_flow) {
            diffflag = 1;
            sametotalflow = Q.top().total_flow;
            //sametrunkflow = Q.top().trunk_flow;
            if(sameflowcount != 0 )
                total_flow.push(sameflowcount);
            sameflowcount = 0;
        }
        if(num == length && diffflag == 0) {
            total_flow.push(++sameflowcount);
        }
        if(num == length && diffflag == 1) {
            total_flow.push(1);
        }
        else {
        //else if(sametrunkflow != Q.top().trunk_flow) {
        //if(sametotalflow == Q.top().total_flow && sametrunkflow != Q.top().trunk_flow) {
            diffflag = 0;
            sameflowcount++;
        }
        Q.pop();

    }

    //total_flow_copy = total_flow;
    //cout<<total_flow.size()<<endl;
    int sum=0;
    cout<<"+++++++++++++++++++++"<<endl;
    while(!total_flow.empty()) {
        sum+=total_flow.front();
        //cout<<total_flow.front()<<endl;
        total_flow_copy.push(total_flow.front());
        total_flow.pop();
    }

    while(!R.empty()) {
        int index=0;
        while(index < total_flow_copy.front()) {
            swap_place.push_back(R.top());
            index++;//cout<<total_flow_copy.front()<<endl;
            R.pop();
        }
        total_flow_copy.pop();

        full_road.push_back(swap_place.front());

       for(unsigned int k=0; k<swap_place.size(); k++) {
            for(list<csvdata>::iterator ik=swap_place.begin(); ik!=swap_place.end(); ik++) {
                csvdata kem = *ik;
                if(full_road.back().end_point.compare(kem.start_point) == 0) {
                    full_road.push_back(kem);//cout<<full_road.back().end_point<<endl;
                }
                if(full_road.front().start_point.compare(kem.end_point) == 0) {
                    full_road.push_front(kem);//cout<<full_road.front().start_point<<endl;
                }
            }
        }

        /*
        for(list<csvdata>::iterator it=full_road.begin(); it!=full_road.end(); it++) {
            csvdata tem = *it;
            cout<<tem.start_point<<"  "<<tem.end_point<<endl;
        }
        */
        //cout<<"full_road.size()="<<full_road.size()<<endl;
        fout<<full_road.back().date<<" "<<full_road.back().road_id<<" "<<full_road.front().start_point<<" "<<full_road.back().end_point<<" "<<full_road.back().total_flow<<" "<<full_road.back().trunk_flow<<" "<<full_road.back().car_flow<<endl;

        swap_place.clear();
        full_road.clear();

    }
    fout.close();

    cout<<"num: "<<num<<"; sum: "<<sum<<"; countnull: "<<countnull;

    return 0;
}

