class Solution {
private:
    std::map<int, int> visited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visit(rooms, 0);

        return visited.size() == rooms.size();
    }


    void visit(vector<vector<int>>& rooms, int room_number) {
        visited[room_number] = 1;
        
        auto room = rooms[room_number];
        
        for (auto key : room) {
            if (visited.find(key) != visited.end()) continue;

            visit(rooms, key);
        }
    }
};