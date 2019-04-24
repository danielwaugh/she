<?php

	$id = htmlspecialchars($_POST["id"]);

        $servername = "localhost";
        $username = "pi";
        $password = "sgadmin";
        $dbname = "SHE";

        $conn = mysqli_connect($servername, $username, $password, $dbname);

	if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
        }

        $sql = "select device_id, status FROM user_" . $id;

	$result = mysqli_query($conn, $sql);

        if (mysqli_num_rows($result) > 0) {
                while($row = mysqli_fetch_assoc($result)) {
                        echo $row["status"] . " ";
                }
        }
        else {
                echo "No Devices";
        }

        mysqli_close($conn);

?>
