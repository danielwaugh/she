package com.example.she_app;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

public class MainActivity extends AppCompatActivity {

    String curData = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        try
        {
            URL url = new URL("http://72.199.201.49:8081/getdevicedata2.php?id=1");
            URLConnection connection = url.openConnection();
            connection.connect();

            BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            String inputLine;

            while((inputLine = in.readLine()) != null)
            {
                curData = inputLine;
            }

            in.close();
        }
        catch(Exception e){ }
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    private class Connection extends AsyncTask {

        @Override
        protected Object doInBackground(Object... arg0) {
            try
            {
                String curButton = (String) arg0[0];
                String UrlString = "http://72.199.201.49:8081/update.php?data=1_" + curButton;
                URL url = new URL(UrlString);
                URLConnection connection = url.openConnection();
                connection.connect();

                BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                String inputLine;

                while((inputLine = in.readLine()) != null)
                {
                    System.out.println(inputLine);
                }

                in.close();
            }
            catch(Exception e){ }
            return null;
        }

    }
    private class Connection2 extends AsyncTask {

        @Override
        protected Object doInBackground(Object... arg0) {
            try
            {
                String curButton = (String) arg0[0];
                String UrlString = "http://72.199.201.49:8081/update.php?data=0_" + curButton;
                URL url = new URL(UrlString);
                URLConnection connection = url.openConnection();
                connection.connect();

                BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                String inputLine;

                while((inputLine = in.readLine()) != null)
                {
                    System.out.println(inputLine);
                }

                in.close();
            }
            catch(Exception e){ }
            return null;
        }

    }

    public void turnOn(View view) {
        String button = "0";
        switch (view.getId()) {
            case R.id.on1:
                button = "1";
                break;
            case R.id.on2:
                button = "2";
                break;
            case R.id.on3:
                button = "3";
                break;
        }
        new Connection().execute(button);
    }

    public void turnOff(View view) {
        String button = "0";
        switch (view.getId()) {
            case R.id.off1:
                button = "1";
                break;
            case R.id.off2:
                button ="2";
                break;
            case R.id.off3:
                button = "3";
                break;
        }
        new Connection2().execute(button);
    }
}
