<?php
	
	if(isset($_POST['log1']))
	{
		if(empty($_POST['hid']) || empty($_POST['hname']) || 
			empty($_POST['tableiban']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
			header("Refresh:0; url=hirer.php");
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");

			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}
			$id = 	$_POST['hid'];
			$iban = $_POST['tableiban'];
			$name = $_POST['hname'];
			
			$res = mysqli_query($link, 
				"INSERT INTO hirer(hid, hname, hiban)
				VALUES ('$id', '$name','$iban')");

			$db_result=mysqli_fetch_array($res);

			if($db_result == NULL) {
				echo "<script>alert('You have successfully inserted.');</script>";

			}
			else{
				echo "<script>alert('Insertion is not successful.');</script>";
			}
			
			header("Refresh:0; url=hirer.php");
		}
		mysqli_close($link);
	}

	if(isset($_POST['namelog']))
	{
	
		if(empty($_POST['hid']) || empty($_POST['hname']))
		{
			header("Refresh:0; url=hirer.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$id = 	$_POST['hid'];
			$name = $_POST['hname'];
			$res1= mysqli_query($link,"SELECT * FROM hirer WHERE hid = '$id' ");
			$res = mysqli_query($link, 
					"UPDATE hirer SET hname='$name' WHERE hid='$id'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=hirer.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=hirer.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

	if(isset($_POST['ibanlog']))
	{
		if(empty($_POST['hid']) || empty($_POST['tableiban']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
		}
		else{

			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$id = 	$_POST['hid'];
			$iban = $_POST['tableiban'];
			$res = mysqli_query($link, 
					"UPDATE hirer SET hiban='$iban' WHERE hid='$id'");
			$res1= mysqli_query($link,"SELECT * FROM hirer WHERE hid = '$id' ");
			$check=mysqli_fetch_array($res1);
			$db_result3=mysqli_fetch_array($res);

			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{
			
				if($db_result3 == NULL) {
					echo "<script>alert('You have successfully updated.');</script>";
					}

				else{
					echo "<script>alert('Update is not successful.');</script>";
				}
    		}
    		header("Refresh:0; url=hirer.php");
			mysqli_close($link);	
		}		
	}

	if(isset($_POST['log3']))
	{
		if(empty($_POST['hid']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}
			
			$id = $_POST['hid'];
			$res = mysqli_query($link, "DELETE FROM hirer WHERE hid='$id'");

			$db_result4=mysqli_fetch_array($res);

			if($db_result4 == NULL) {
				echo "<script>alert('You have successfully deleted.');</script>";
			}
			else{
				echo "<script>alert('Deletion is not successful.');</script>";
			}	
		}
		mysqli_close($link);
		header("Refresh:0; url=hirer.php");
	}


?>