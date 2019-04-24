<?php

	if (isset($_POST['data'])) {
                $data = $_POST['data'];
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

        for ($i = 0; $i < 6; $i++){
                if($data[$i] == "1"){
                        $sql = 'update user_1 set status = "ON" where device_id = ' . (string)($i + 1);
                }
                if($data[$i] == "0") {
                        $sql = 'update user_1 set status = "OFF" where device_id = ' . (string)($i + 1);
                }
                mysqli_query($conn, $sql);
        }


        mysqli_close($conn);

?>