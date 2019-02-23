const char homePageHTML1[] PROGMEM = R"=====(
<HTML>
	<HEAD>
			<TITLE>SHE Smart Plug</TITLE>
      <style type="text/css">
      body {
        background-color: #79BBE4;
      }

      #header {
        font-family: 'Oswald';
        text-shadow: 1px 1px red;
      }

      #submit {
        background-color: #EE1515;
        padding: .5em;
        -moz-border-radius: 5px;
        -webkit-border-radius: 5px;
        border-radius: 6px;
        color: #fff;
        font-family: 'Oswald';
        font-size: 20px;
        text-decoration: none;
        border: none;
      }

      #submit:hover {
        border: none;
        background: #3F2FE7;
        box-shadow: 0px 0px 1px #777;
      }
      </style>
	</HEAD>
<BODY>
	<CENTER>
)=====";

const char homePageHTML2[] PROGMEM = R"=====(
    <br><br>
      <h1 id="header">Welcome to your smart Plug</h1>
      <h3 id="header">Use the buttons below to view settings for the smart plug</h3>
      <br>
    <form action="/redirect1">
    <input id="submit" type="submit" value="Configure Smart Plug" />
    </form>
    <form action="/checkStatus">
      <input id="submit" type="submit" value="Check Status of Smart Plug" />
    </form>
    <form action="/leaveSetup">
      <input id="submit" type="submit" value="Leave Setup Mode" />
    </form>
  </CENTER> 
</BODY>
</HTML>
)=====";

const char configurePage1HTML1[] PROGMEM = R"=====(
<HTML>
  <HEAD>
      <TITLE>Configure Smart Plug</TITLE>
      <style type="text/css">
      body {
        background-color: #79BBE4;
      }

      #header {
        font-family: 'Oswald';
        text-shadow: 1px 1px red;
      }

      #submit {
        background-color: #EE1515;
        padding: .5em;
        -moz-border-radius: 5px;
        -webkit-border-radius: 5px;
        border-radius: 6px;
        color: #fff;
        font-family: 'Oswald';
        font-size: 20px;
        text-decoration: none;
        border: none;
      }

      #submit:hover {
        border: none;
        background: #3F2FE7;
        box-shadow: 0px 0px 1px #777;
      }
      
      .container {
        position: relative;
        padding-left: 35px;
        margin-bottom: 12px;
        cursor: pointer;
        font-size: 22px;
        -webkit-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
      }

      .container input {
        position: absolute;
        opacity: 0;
        cursor: pointer;
      }

      .checkmark {
        position: absolute;
        top: 0;
        left: 0;
        height: 25px;
        width: 25px;
        background-color: #eee;
        border-radius: 50%;
      }
      
      .container:hover input ~ .checkmark {
        background-color: #ccc;
      }

      .container input:checked ~ .checkmark {
        background-color: #EE1515;
      }

      .checkmark:after {
        content: "";
        position: absolute;
        display: none;
      }

      .container input:checked ~ .checkmark:after {
        display: block;
      }

      .container .checkmark:after {
         top: 9px;
        left: 9px;
        width: 8px;
        height: 8px;
        border-radius: 50%;
        background: white;
      }
      </style>
  </HEAD>
<BODY>
  <CENTER>
)=====";

const char configurePage1HTML2[] PROGMEM = R"=====(
      <br><br>
      <h1 id="header">Configure Your Smart Plug</h1>
      <h3 id="header">Please select the network labeled SHE</h3>
      <br>
)=====";

const char configurePage1HTML3[] PROGMEM = R"=====(
  <br>
      <form action="/redirect1">
      <input id="submit" type="submit" value="Refresh Page" />
      </form>
  </CENTER> 
  </CENTER> 
</BODY>
</HTML>
)=====";


const char configurePage2HTML1[] PROGMEM = R"=====(
<HTML>
  <HEAD>
      <TITLE>Configure Smart Plug</TITLE>
      <style type="text/css">
      body {
        background-color: #79BBE4;
      }

      #header {
        font-family: 'Oswald';
        text-shadow: 1px 1px red;
      }

      #submit {
        background-color: #EE1515;
        padding: .5em;
        -moz-border-radius: 5px;
        -webkit-border-radius: 5px;
        border-radius: 6px;
        color: #fff;
        font-family: 'Oswald';
        font-size: 20px;
        text-decoration: none;
        border: none;
      }

      #submit:hover {
        border: none;
        background: #3F2FE7;
        box-shadow: 0px 0px 1px #777;
      }
      </style>
  </HEAD>
<BODY>
  <CENTER>
)=====";

const char configurePage2HTML2[] PROGMEM = R"=====(
<br><br>
      <h1 id="header">Authentication</h1>
      <h3 id="header">Please enter the password found on the bottom of the central HUB</h3>
      <br>
)=====";

const char configurePage2HTML3[] PROGMEM = R"=====(
  </CENTER> 
</BODY>
</HTML>
)=====";

const char configurePage3HTML1[] PROGMEM = R"=====(
<HTML>
  <HEAD>
      <TITLE>Configure Smart Plug</TITLE>
      <style type="text/css">
      body {
        background-color: #79BBE4;
      }

      #header {
        font-family: 'Oswald';
        text-shadow: 1px 1px red;
      }

      #submit {
        background-color: #EE1515;
        padding: .5em;
        -moz-border-radius: 5px;
        -webkit-border-radius: 5px;
        border-radius: 6px;
        color: #fff;
        font-family: 'Oswald';
        font-size: 20px;
        text-decoration: none;
        border: none;
      }

      #submit:hover {
        border: none;
        background: #3F2FE7;
        box-shadow: 0px 0px 1px #777;
      }
      </style>
  </HEAD>
<BODY>
  <CENTER>
)=====";

const char configurePage3HTML2[] PROGMEM = R"=====(
  </CENTER> 
</BODY>
</HTML>
)=====";

const char checkStatusHTML1[] PROGMEM = R"=====(
<HTML>
  <HEAD>
      <TITLE>Check Smart Plug Status</TITLE>
      <style type="text/css">
      body {
        background-color: #79BBE4;
      }

      #header {
        font-family: 'Oswald';
        text-shadow: 1px 1px red;
      }

      #submit {
        background-color: #EE1515;
        padding: .5em;
        -moz-border-radius: 5px;
        -webkit-border-radius: 5px;
        border-radius: 6px;
        color: #fff;
        font-family: 'Oswald';
        font-size: 20px;
        text-decoration: none;
        border: none;
      }

      #submit:hover {
        border: none;
        background: #3F2FE7;
        box-shadow: 0px 0px 1px #777;
      }
      </style>
  </HEAD>
<BODY>
  <CENTER>
)=====";

const char leavePageHTML1[] PROGMEM = R"=====(
<HTML>
  <HEAD>
      <TITLE>Configure Smart Plug</TITLE>
      <style type="text/css">
      body {
        background-color: #79BBE4;
      }

      #header {
        font-family: 'Oswald';
        text-shadow: 1px 1px red;
      }

      #submit {
        background-color: #EE1515;
        padding: .5em;
        -moz-border-radius: 5px;
        -webkit-border-radius: 5px;
        border-radius: 6px;
        color: #fff;
        font-family: 'Oswald';
        font-size: 20px;
        text-decoration: none;
        border: none;
      }

      #submit:hover {
        border: none;
        background: #3F2FE7;
        box-shadow: 0px 0px 1px #777;
      }
      </style>
  </HEAD>
<BODY>
  <CENTER>
  )=====";

const char leavePageHTML2[] PROGMEM = R"=====(
  <h1 id="header">You have Left Setup Mode</h1>
  <h3 id="header">You can close the page now</h3>
  <h3 id="header">If you would like to enter setup again, press the button on the smart plug for 5 seconds and connect to the network again</h3>
  </CENTER> 
</BODY>
</HTML>
)=====";

const char sheImage[] PROGMEM = R"=====(
<img src='data:image/png;base64,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' alt=''>
)=====";
