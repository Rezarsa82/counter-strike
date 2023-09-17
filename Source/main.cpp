#include <iostream>
#include <string>

#include "Data.pb.h"
#include "Team/Weapon/Weapon.h"
#include "GameFeatures/Configuration/Configuration.h"
#include "GameFeatures/ControlCenter/ControlCenter.h"
#include "GameFeatures/Exception/Exception.h"

using namespace std;

void decide(string&, ControlCenter&);

int main() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  try {
    int R, n;
    auto controller = new ControlCenter();
    string task, time;

    cin >> R;
    for (int i = 0; i < R; ++i) {
      controller->NewRound();
      cin >> task >> n;
      for (int j = 0; j < n; ++j) {
        cin >> task;
        decide(task, *controller);
      }
    }
  }
  catch (Exception &err){
    cout << err.GetError() << endl;
  }
  google::protobuf::ShutdownProtobufLibrary();
  return 0;
}

void decide(string &task, ControlCenter &controller){
  try {
    string time, name, team, weapon_name;
    if (task == "ADD-USER") {
      cin >> name >> team >> time;
      cout << controller.AddUser(name, Configuration::TeamEnum(team), time) << endl;
    }
    else if (task == "GET-HEALTH") {
      cin >> name >> time;
      cout << controller.GetHealth(name) << endl;
    }
    else if (task == "GET-MONEY") {
      cin >> name >> time;
      cout << controller.GetMoney(name) << endl;
    }
    else if (task == "BUY") {
      cin >> name >> weapon_name >> time;
      cout << controller.Buy(name, weapon_name, time) << endl;
    }
    else if (task == "TAP") {
      string name2;
      cin >> name >> name2 >> weapon_name >> time;
      cout << controller.Tap(name, name2, Configuration::WeaponEnum(weapon_name)) << endl;
    }
    else if (task == "SCORE-BOARD") {
      cin >> time;
      controller.ScoreBoard();
    }
  }
  catch (Exception &err){
    cout << err.GetError() << endl;
  }
}