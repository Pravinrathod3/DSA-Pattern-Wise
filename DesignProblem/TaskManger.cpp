#include<bits/stdc++.h>
using namespace std;

class TaskManager {
public:

    multiset<pair<int, pair<int, int>>> pq;
    unordered_map<int, pair<int, int>> mpp;

    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i=0; i<n; i++){
            pq.insert({tasks[i][2], {tasks[i][1], tasks[i][0]}});
            mpp[tasks[i][1]] = {tasks[i][2], tasks[i][0]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.insert({priority, {taskId, userId}});
        mpp[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        auto [oldPriority, userId] = mpp[taskId];

        pq.erase({oldPriority, {taskId, userId}});
        pq.insert({newPriority, {taskId, userId}});

        mpp[taskId].first = newPriority;
    }
    
    void rmv(int taskId) {
        auto [oldPriority, userId] = mpp[taskId];
        pq.erase({oldPriority, {taskId, userId}});
        mpp.erase(taskId);
    }
    
    int execTop() {
        if (pq.empty()) return -1;
        
        auto [priority, task] = *pq.rbegin();
        rmv(task.first);

        return task.second;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main(){
    vector<vector<int>> tasks = {
        {1, 101, 5},
        {2, 102, 3},
        {1, 103, 4}
    };

    TaskManager* obj = new TaskManager(tasks);
    obj->add(2, 104, 6);
    obj->edit(102, 7);
    obj->rmv(101);
    cout << obj->execTop() << endl; // Should return the userId of the highest priority task

    return 0;   
}
