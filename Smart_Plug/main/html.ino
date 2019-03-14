void homePage() {
  String htmlString1 = homePageHTML1;
  String htmlString2 = homePageHTML2;
  String picture = sheImage; 
  server.send(200, "text/html", htmlString1 + picture + htmlString2); 
}

void redirect1() {
  server.send(200, "text/html", "<HTML><head><meta http-equiv=\"refresh\" content=\"5;url=/configurePage1\" /></head><body><h1>redirecting</h1></body></HTML>");
  
  int numberOfNetworks = WiFi.scanNetworks();
  String openNetworks = "<form action=\"/configurePage2\" method=\"post\">";
  for(int i = 0; i < numberOfNetworks; i++)
  {
    openNetworks += "<label id=\"header\" class=\"container\">" + WiFi.SSID(i);
    openNetworks += "<input type=\"radio\" name=\"radio\" ";
    openNetworks += "value=\"" + WiFi.SSID(i) + "\" ";
    openNetworks += "\"><span class=\"checkmark\"></span></label><br><br>";
  }
  openNetworks += "<input id=\"submit\" type=\"submit\" value=\"Submit\" /></form>";

  temp = openNetworks;
}

void configurePage1() {
  String htmlString1 = configurePage1HTML1;
  String htmlString2 = configurePage1HTML2;
  String htmlString3 = configurePage1HTML3;
  String picture = sheImage;
  String openNetworks = temp;
  server.send(200, "text/html", htmlString1 + picture + htmlString2 + openNetworks + htmlString3);
}

void configurePage2() {
  String htmlString1 = configurePage2HTML1;
  String htmlString2 = configurePage2HTML2;
  String htmlString3 = configurePage2HTML3;
  String picture = sheImage;
  tempSSID = server.arg(0);
  String Intermediate = "<h3 id=\"header\">";
  if (server.args() > 0) {
    Intermediate += server.arg(0);
    Intermediate += "</h3><form action=\"/redirect2\" method=\"post\">";
    Intermediate += "<h4 id=\"header\">Enter Password</h4><input type=\"password\" name=\"password\"><br><br>";
    Intermediate += "<input id=\"submit\" type=\"submit\" value=\"Connect\" /></form>";
  }
  else {
    Intermediate += "ERROR</h3>";
  }

  server.send(200, "text/html", htmlString1 + picture + htmlString2 + Intermediate + htmlString3);
}

void redirect2() {
  server.send(200, "text/html", "<HTML><head><meta http-equiv=\"refresh\" content=\"8;url=/configurePage3\" /></head><body><h1>redirecting</h1></body></HTML>");
  String Intermediate = "<h3 id=\"header\">";
  if (server.args() > 0) {
    tempPassword = server.arg(0);
    WiFi.begin(tempSSID.c_str(), tempPassword.c_str());
    int i;
    for(i = 0; i < 7; i++) {
      if (WiFi.status() == WL_CONNECTED) {
        if (WiFi.SSID() == tempSSID) {
          Intermediate += "Your Smart Plug is already connected to this network</h3>";
          break;
        }
        Intermediate += "Your Smart Plug has successfully been added to the system</h3>";
        currentSSID = tempSSID;
        currentPassword = tempPassword;
        break;
      }
      delay(1000);
      if(i == 4) {
        Intermediate += "Could Not Connect to Network, Please Try again</h3>";
        break;
      }
    }
  }
  else {
    Intermediate += "ERROR</h3>";
  }
  Intermediate += "<form action=\"/\"><input id=\"submit\" type=\"submit\" value=\"Home Page\" /></form>";
  temp = Intermediate;
}

void configurePage3() {
  String htmlString1 = configurePage3HTML1;
  String htmlString2 = configurePage3HTML2;
  String picture = sheImage;
  String Intermediate = temp;
  server.send(200, "text/html", htmlString1 + picture + Intermediate + htmlString2);
}

void checkStatus() {
  String htmlString1 = checkStatusHTML1;
  String picture = sheImage;
  String Intermediate = "<h1 id=\"header\">Smart Plug Status</h1><br><h3 id=\"header\">Your Smart Plug is currently ";
  if (WiFi.status() == WL_CONNECTED) {
    Intermediate += "connected to the network " + WiFi.SSID();
  }
  else {
    Intermediate += "disconnected from the network";
  }
  Intermediate += "</h3><br><br><form action=\"/\"><input id=\"submit\" type=\"submit\" value=\"Home Page\" /></form></center><body></HTML>";
  server.send(200, "text/html", htmlString1 + picture + Intermediate);
}

void leaveSetup() {
  String htmlString1 = leavePageHTML1;
  String htmlString2 = leavePageHTML2;
  String picture = sheImage;
  server.send(200, "text/html", htmlString1 + picture + htmlString2);
  delay(1000);
  currentMode = 0;
}

void webServerSetup() {
  server.on("/", homePage);
  server.on("/redirect1", redirect1);  
  server.on("/configurePage1", configurePage1);
  server.on("/configurePage2", configurePage2);
  server.on("/redirect2", redirect2);
  server.on("/configurePage3", configurePage3);
  server.on("/checkStatus", checkStatus);
  server.on("/leaveSetup", leaveSetup);

  server.begin();
}
