<?php

if(isset($_POST['log1']))
{
		if(empty($_POST['hid']) || empty($_POST['cid']) 
			|| empty($_POST['color']) || empty($_POST['price']) 
			|| empty($_POST['avail']) || empty($_POST['model']) 
			|| empty($_POST['gtype'])|| empty($_POST['photo']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
			header("Refresh:0; url=car.php");
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");

			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = $_POST['cid'];
			$thid = $_POST['hid'];
			$tcolor = $_POST['color'];
			$tprice =  $_POST['price'];
			$tavail = 	$_POST['avail'];
			$tmodel = $_POST['model'];
			$tgtype = $_POST['gtype'];
			$tphoto =  $_POST['photo'];

			$res1= mysqli_query($link,"SELECT * FROM hirer WHERE hid = '$thid' ");
			$res = mysqli_query($link, 
				"INSERT INTO car(hid, cid, color, price, avail, model, gtype, photo) VALUES ('$thid', '$tcid','$tcolor', '$tprice', '$tavail', '$tmodel','$tgtype', '$tphoto')");

			$db_result=mysqli_fetch_array($res);
			$check=mysqli_fetch_array($res1);

			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID of the hirer does not exist');</script>";
    		} 
    		else{

				if($db_result == NULL) {
					echo "<script>alert('You have successfully inserted.');</script>";

				}
				else{
					echo "<script>alert('Insertion is not successful.');</script>";
				}
			}
			header("Refresh:0; url=car.php");
		}
	mysqli_close($link);
}

if(isset($_POST['colorlog']))
	{
	
		if(empty($_POST['cid']) || empty($_POST['color']))
		{
			header("Refresh:0; url=car.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = 	$_POST['cid'];
			$tcolor = $_POST['color'];
			$res1= mysqli_query($link,"SELECT * FROM car WHERE cid = '$tcid' ");
			$res = mysqli_query($link, 
					"UPDATE car SET color='$tcolor' WHERE cid='$tcid'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=car.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=car.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

if(isset($_POST['modellog']))
	{
	
		if(empty($_POST['cid']) || empty($_POST['model']))
		{
			header("Refresh:0; url=car.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = 	$_POST['cid'];
			$tmodel = $_POST['model'];
			$res1= mysqli_query($link,"SELECT * FROM car WHERE cid = '$tcid' ");
			$res = mysqli_query($link, 
					"UPDATE car SET model='$tmodel' WHERE cid='$tcid'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=car.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=car.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

	if(isset($_POST['pricelog']))
	{
	
		if(empty($_POST['cid']) || empty($_POST['price']))
		{
			header("Refresh:0; url=car.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = 	$_POST['cid'];
			$tprice = $_POST['price'];
			$res1= mysqli_query($link,"SELECT * FROM car WHERE cid = '$tcid' ");
			$res = mysqli_query($link, 
					"UPDATE car SET price='$tprice' WHERE cid='$tcid'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=car.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=car.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

if(isset($_POST['gtypelog']))
	{
	
		if(empty($_POST['cid']) || empty($_POST['gtype']))
		{
			header("Refresh:0; url=car.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = 	$_POST['cid'];
			$tgtype = $_POST['gtype'];
			$res1= mysqli_query($link,"SELECT * FROM car WHERE cid = '$tcid' ");
			$res = mysqli_query($link, 
					"UPDATE car SET gtype='$tgtype' WHERE cid='$tcid'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=car.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=car.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

if(isset($_POST['availlog']))
	{
	
		if(empty($_POST['cid']) || empty($_POST['avail']))
		{
			header("Refresh:0; url=car.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = 	$_POST['cid'];
			$tavail = $_POST['avail'];
			$res1= mysqli_query($link,"SELECT * FROM car WHERE cid = '$tcid' ");
			$res = mysqli_query($link, 
					"UPDATE car SET avail='$tavail' WHERE cid='$tcid'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=car.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=car.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

if(isset($_POST['photolog']))
	{
	
		if(empty($_POST['cid']) || empty($_POST['photo']))
		{
			header("Refresh:0; url=car.php");
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$tcid = 	$_POST['cid'];
			$tphoto = $_POST['photo'];
			$res1= mysqli_query($link,"SELECT * FROM car WHERE cid = '$tcid' ");
			$res = mysqli_query($link, 
					"UPDATE car SET photo='$tphoto' WHERE cid='$tcid'");
			$check=mysqli_fetch_array($res1);
			$db_result1=mysqli_fetch_array($res);
			if($check == NULL)   // if there is no such user like that.
    		{
      			echo "<script>alert('The ID does not exist');</script>";
    		} 
    		else{

				if($db_result1 == NULL) {
					header("Refresh:0; url=car.php");
					echo "<script>alert('You have successfully updated.');</script>";
				}

				else{
					header("Refresh:0; url=car.php");
					echo "<script>alert('Update is not successful.');</script>";
				}
			}
		}
	}

if(isset($_POST['log3']))
	{
		if(empty($_POST['cid']))
		{
  			echo "<script>alert('You have an empty field.');</script>";
		}

		else{
			
			$link = mysqli_connect("localhost", "root", "", "carproject");
			if($link === false){
    			die("ERROR: Could not connect. " .mysqli_connect_error());
			}

			$name = $_POST['cid'];
			$res = mysqli_query($link, 
				"DELETE FROM car WHERE cid='$name'");

			$db_result4=mysqli_fetch_array($res);

			if($db_result4 == NULL) {
				echo "<script>alert('You have successfully deleted.');</script>";
			}
			else{
				echo "<script>alert('Deletion is not successful.');</script>";
			}	
		}
		mysqli_close($link);
		header("Refresh:0; url=car.php");
	}
?>