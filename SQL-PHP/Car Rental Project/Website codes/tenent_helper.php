<?php
	
	if(isset($_POST['log1']))
	{
		if(empty($_POST['tid']) || empty($_POST['tname']) || 
			empty($_POST['tage'] || empty($_POST['tableiban'])))
		{
  			echo "<script>alert('You have an empty field.');</script>";
			header("Refresh:0; url=tenant.php");
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");

			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}
			$id = 	$_POST['tid'];
			$iban = $_POST['tableiban'];
			$name = $_POST['tname'];
			$age =  $_POST['tage'];

			$res = mysqli_query($link, 
				"INSERT INTO tenant(tid, tname, Age, tiban)
				VALUES ('$id', '$name','$age', '$iban')");

			$db_result=mysqli_fetch_array($res);

			if($db_result == NULL) {
				echo "<script>alert('You have successfully inserted.');</script>";

			}
			else{
				echo "<script>alert('Insertion is not successful.');</script>";
			}
			
			header("Refresh:0; url=tenant.php");
		}
		mysqli_close($link);
	}

	if(isset($_POST['namelog']))
	{
	
		if(empty($_POST['tid']) || empty($_POST['tname']))
		{
			header("Refresh:0; url=tenant.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$id = 	$_POST['tid'];
			$name = $_POST['tname'];
			$res1= mysqli_query($link,"SELECT * FROM tenant WHERE tid = '$id' ");
			$res = mysqli_query($link, 
					"UPDATE tenant SET tname='$name' WHERE tid='$id'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=tenant.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=tenant.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

	if(isset($_POST['agelog']))
	{
		if(empty($_POST['tid']) || empty($_POST['tage']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
		}
		else{

			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$id = 	$_POST['tid'];
			$age =  $_POST['tage'];
			$res = mysqli_query($link, 
					"UPDATE tenant SET Age='$age' WHERE tid='$id'");
			$res1= mysqli_query($link,"SELECT * FROM tenant WHERE tid = '$id' ");
			$check=mysqli_fetch_array($res1);
			$db_result2=mysqli_fetch_array($res);

			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{
					
				if($db_result2 == NULL) {
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
		header("Refresh:0; url=tenant.php");
		mysqli_close($link);
	}

	if(isset($_POST['ibanlog']))
	{
		if(empty($_POST['tid']) || empty($_POST['tableiban']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
		}
		else{

			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$id = 	$_POST['tid'];
			$iban = $_POST['tableiban'];
			$res = mysqli_query($link, 
					"UPDATE tenant SET tiban='$iban' WHERE tid='$id'");
			$res1= mysqli_query($link,"SELECT * FROM tenant WHERE tid = '$id' ");
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
    		header("Refresh:0; url=tenant.php");
			mysqli_close($link);	
		}		
	}

	if(isset($_POST['log3']))
	{
		if(empty($_POST['tid']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$name = $_POST['tid'];
			$res = mysqli_query($link, 
				"DELETE FROM tenant WHERE tid='$name'");

			$db_result4=mysqli_fetch_array($res);

			if($db_result4 == NULL) {
				echo "<script>alert('You have successfully deleted.');</script>";
			}
			else{
				echo "<script>alert('Deletion is not successful.');</script>";
			}	
		}
		mysqli_close($link);
		header("Refresh:0; url=tenant.php");
	}
?>