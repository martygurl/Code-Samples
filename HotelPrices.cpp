/********************************************************************************************************************************************************
 * The price of a standard hotel room and hotel apartment are given as:
 *       Hotel Room: 50*bedrooms + 100*bathrooms
 *       Hotel Apartment: The price of a standard room with the same number bedrooms and bathrooms plus 100
 * Calculate the correct price for the rooms booked
 * 
 * Input Format:
 * In the first line, there is a single integer n denoting the number of rooms booked for today.
 * After that n lines follow. Each of these lines begins with a room_type which is either standard or apartment, 
 * and is followed by the number of bedrooms and the number of bathrooms in this room.
 * 
 * Output Format:
 *  It calculates the total profit by iterating through the vector of all rooms read from the input.
 * 
 * Constraints
 * 1 <= n <= 100
 * there is at least 1 and at most 5 bedrooms in a room
 * there is at least 1 and at most 5 bathrooms in a room
 * 
 * Example input:
 * 2
 * standard 3 1
 * apartment 1 1
 * 
 * Example output:
 * 500
 * ******************************************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    virtual int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}