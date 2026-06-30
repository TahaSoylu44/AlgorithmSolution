#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

struct MotorCycle
{
    string id;
    string license_plate;
    int speed;

    bool operator<(const MotorCycle& rhs) const
    {
        if (speed == rhs.speed) return id > rhs.id;
        return speed > rhs.speed;
    }
};

struct Truck
{
    string id;
    string license_plate;
    int speed;
};

struct Car
{
    string id;
    string license_plate;
    int speed;

    bool operator<(const Car& rhs) const
    {
        return license_plate > rhs.license_plate;
    }
};

struct Bus
{
    string id;
    string license_plate;
    int speed;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<MotorCycle> pq_motor;
    priority_queue<Car> pq_car;
    stack<Bus> stack_bus;
    queue<Truck> queue_truck;

    int n;
    cin >> n;

    string cmd, type, id, plate;
    int speed;

    Truck truck;
    Car car;
    MotorCycle motor;
    Bus bus;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "ARRIVE")
        {
            cin >> type >> id >> plate >> speed;

            if (type == "TRUCK")
            {
                truck = {id, plate, speed};
                queue_truck.push(truck);
            }
            else if (type == "CAR")
            {
                car = {id, plate, speed};
                pq_car.push(car);
            }
            else if (type == "MOTORCYCLE")
            {
                motor = {id, plate, speed};
                pq_motor.push(motor);
            }
            else if (type == "BUS")
            {
                bus = {id, plate, speed};
                stack_bus.push(bus);
            }
        }
        else if (cmd == "DEPART")
        {
            while (!pq_motor.empty())
            {
                motor = pq_motor.top();
                pq_motor.pop();
                std::cout << motor.id << '\n';
            }
            while (!pq_car.empty())
            {
                car = pq_car.top();
                pq_car.pop();
                std::cout << car.id << '\n';
            }
            while (!stack_bus.empty())
            {
                bus = stack_bus.top();
                stack_bus.pop();
                std::cout << bus.id << '\n';
            }
            while (!queue_truck.empty())
            {
                truck = queue_truck.front();
                queue_truck.pop();
                std::cout << truck.id << '\n';
            }
        }
    }
    
    return 0;
}