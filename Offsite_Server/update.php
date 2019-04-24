<?php

	if (isset($_GET['data'])) {
                $data = $_GET['data'];
	}

	$data = explode("_", $data);

        $servername = "localhost";
        $username = "pi";
        $password = "sgadmin";
        $dbname = "SHE";

        $conn = mysqli_connect($servername, $username, $password, $dbname);

	if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
        }

        if($data[0] == "1"){
                $sql = 'update user_1 set status = "ON" where device_id = ' . $data[1];
        }
        if($data[0] == "0"){
                $sql = 'update user_1 set status = "OFF" where device_id = ' . $data[1];
        }

        mysqli_query($conn, $sql);

        mysqli_close($conn);

?>
