class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        // Pair position and speed
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        
        // Sort by position descending
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double maxTime = 0;
        
        for (auto &car : cars) {
            int pos = car.first;
            int spd = car.second;
            
            double time = (double)(target - pos) / spd;
            
            if (time > maxTime) {
                fleets++;
                maxTime = time;
            }
        }
        
        return fleets;
    }
};