#include <iostream>
#include <queue>
#include <vector>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &request) {
Response res(false, 0);
        if(finish_time_.empty()){
            res.start_time = request.arrival_time;
            finish_time_.push(request.arrival_time + request.process_time);
        }
        else{
            while(!finish_time_.empty()){
                if(request.arrival_time >= finish_time_.front())
                    finish_time_.pop();
                else{
                    if(finish_time_.size() == size_){
                        res.start_time = 0;
                        res.dropped = true;
                    }
                    else if(finish_time_.size() < size_){
                        res.start_time = finish_time_.back();
                        finish_time_.push(res.start_time + request.process_time);
                    }
                    break;
                }

            }
            if(finish_time_.empty()){
                res.start_time = request.arrival_time;
                finish_time_.push(request.arrival_time + request.process_time);
            }
        }
        return res;
    }
private:
    int size_;
    wqueue <int> finish_time_;
};

vector <Request> ReadRequests(ifstream &fin) {
    vector <Request> requests;
    int count;
    fin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        fin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    fin.close();
    return requests;
}

vector <Response> ProcessRequests(const vector <Request> &requests, Buffer *buffer) {
    vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const vector <Response> &responses, ifstream &fa) {
    for (int i = 0; i < responses.size(); ++i){
        int answer;
        fa >> answer;
        if((responses[i].dropped ? -1 : responses[i].start_time) != answer){
            cout << "line " << i << " different to answer" << endl;
        }
    }
    fa.close();
}


int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
