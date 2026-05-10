#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct Flight{
    string dest;
    int cost;
};

class FlightGraph{
    private: 
        map<string, vector<Flight>> graph;

    public:

        void addFlight(string src, string dest, int cost){
            graph[src].push_back({dest, cost});
            graph[dest].push_back({src, cost});
        }

        void checkDirectFlight(string src, string dest){
             if(graph.find(src) == graph.end()){
                cout << "City " << src << " not found." << endl;
                return ;
             }

             for(auto &flight : graph[src]){
                if(flight.dest == dest){
                    cout << "Direct flight found from " << src << " to " << dest << " with cost: " << flight.cost << endl;
                    return;
                }
             }
             cout << "No direct flight found from " << src << " to " << dest << endl;
             return ;
        }

        void displayAllFlights(){
            cout << "All available flights." << endl;
            for(auto &city : graph){
                cout << city.first << " -> ";
                for(auto &flight : city.second){
                    cout << "( " << flight.dest <<", " << flight.cost << ") ";
                }
                cout << endl;
            }
            return ;
        }

        void countFlight(string city){
            if(graph.find(city) == graph.end()){
                cout << "City " << city << " not found." << endl;
                return ;
            }

            cout << "The total flights from " << city << " is " << graph[city].size() << endl;
            return ;
        }

};

int main(){
    FlightGraph g;

    g.addFlight("Delhi", "Mumbai", 1500);
    g.addFlight("Mumbai", "Kerla", 3000);
    g.addFlight("Delhi", "Chennai", 2000);
    g.addFlight("Mumbai", "Kolkata", 1800);
    g.addFlight("Chennai", "Kolkata", 2500);

    int choice ;
    string src, dest;

    do{
                cout << "\n--- Flight Operations Menu ---\n";
        cout << "1. Check Direct Flight\n";
        cout << "2. Display All Flights\n";
        cout << "3. Count Flights from a City\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter source city: ";
                cin >> src;
                cout << "Enter destination city: ";
                cin >> dest;
                g.checkDirectFlight(src, dest);
                break;
            case 2:
                g.displayAllFlights();
                break;
            case 3:
                cout << "Enter city : ";
                cin >>src;
                g.countFlight(src);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice";
                break;
        }
    } while(choice != 4);
    return 0;
}