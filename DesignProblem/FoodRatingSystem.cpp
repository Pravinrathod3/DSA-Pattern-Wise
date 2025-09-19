#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    unordered_map<string, pair<string, int>> mpp;
    unordered_map<string, set<pair<int, string>>> hash;

    FoodRatings(const vector<string>& foods,const  vector<string>& cuisines,const vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; i++){
            mpp[foods[i]] = {cuisines[i], ratings[i]};
            hash[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {

        auto [cuisine, prevrating] = mpp[food];

        hash[cuisine].erase({-prevrating, food});
        hash[cuisine].insert({-newRating, food});

        mpp[food].second = newRating;

    }
    
    string highestRated(string cuisine) {
        return hash[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main(){
    FoodRatings* obj = new FoodRatings(
        vector<string>{"kimchi", "miso", "sushi", "ramen", "bulgogi"},
        vector<string>{"korean", "japanese", "japanese", "japanese", "korean"},
        vector<int>{9, 12, 8, 15, 7}
    );
    cout << obj->highestRated("korean") << endl; // Output: "kimchi"
    obj->changeRating("sushi", 16);
    cout << obj->highestRated("japanese") << endl; // Output: "sushi"

    delete obj;
    return 0;
}