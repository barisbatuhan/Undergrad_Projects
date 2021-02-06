<html>

<?php
	error_reporting(E_ALL ^ E_DEPRECATED);
	$link = mysqli_connect("localhost", "root", "", "carproject");

	// Check connection
	if($link === false){
    	die("ERROR: Could not connect. " .mysqli_connect_error());
	}
?>

<head>
	<meta charset="UTF-8">
	<link rel="stylesheet" href="adminpage.css">
</head>

<body background="img/adminback2.jpg">
	
	<div align="center" class="headpart">
		<div style="width:50%;border:0px;float:left;color:white">
			<img src="img/adminlogo.png" style="height:100px; width:250px; padding-right:30px;"> 
		</div>
		<div onclick = "location.href = 'hirer.php'" class="topbuttons" type="button" style="width:16.66%;border:0px;float:left;"> Hirer </div>
		<div onclick = "location.href = 'tenant.php'" class="topbuttons" type="button" type="button" style="width:16.66%;border:0px;float:left;"> Tenant </div>
		<div class="topbuttons" type="button" type="button" style="width:16.66%;border:0px;float:left;"> Car </div>
	</div>

	<?php
	
		$result = mysqli_query($link,"SELECT * FROM car");
		echo "<table border='1px solid orange' style='width:100%; background-color: orange; text-align:center; font-family:Calibri; font-size:20px'>
		<tr>
		<th>Hirer ID</th>
		<th>Car ID</th>
		<th>Color</th>
		<th>Price</th>
		<th>Availability (1-yes 2-no) </th>
		<th>Model</th>
		<th>Gear-type (1-auto 2-manual)</th>
		<th>Photo</th>
		</tr>";

		while($row = mysqli_fetch_array($result))
		{
			echo "<tr>";
			echo "<td>" . $row['hid'] . "</td>";
			echo "<td>" . $row['cid'] . "</td>";
			echo "<td>" . $row['color'] . "</td>";
			echo "<td>" . $row['price'] . "</td>";
			echo "<td>" . $row['avail'] . "</td>";
			echo "<td>" . $row['model'] . "</td>";
			echo "<td>" . $row['gtype'] . "</td>";
			echo "<td>" . $row['photo'] . "</td>";
			echo "</tr>";
		}
		echo "</table>";
	?>
	
	<form method=POST action='car_helper.php' align="center" style='width:33.3%; height: 70%; background-color:yellow;margin-top:1%; font-family:Georgia; float:left; border-right: 1px solid black'>
        <div class=logintext style="width:100%;">
        	<br>
        	<p style="font-style: bold; font-size: 30px"> INSERT A NEW CAR </p>
        	<br>
        	<div style="width:50%; float:left"
        	<label for="text">Nationality ID of the Hirer (11 Digits):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="hid">
            <br>
            <br>
            <label for="text">Car ID:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="cid">
            <br>
            <br>
            <br>
            <label for="text">Color:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="color">
            <br>
            <br>
            <br>
            <label for="text">Price (Integer):</label>
            <br>
        	
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="price">
            <br>
            <br>
            <br>
        	<br>
            </div>
            <div style="width:50%; float:left"
            <label for="text">Availability (1-yes 2-no):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="avail">
            <br>
            <br>
            <label for="text">Model:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="model">
            <br>
            <br>
            <br>
            <label for="text">Gear-Type (1-auto 2-manual):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="gtype">
            <br>
            <br>
            <br>
            <label for="text">Photo:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="photo">
            <br>
            <br>
            <br>
        	<br>
        	</div>
            <input style="width:80%; height:50px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="log1">
        </div>
    </form>

    <form method=POST action='car_helper.php' align="center" style='width:33.3%; height: 70%; background-color:yellow;margin-top:1%; font-family:Georgia; float:left; border-right: 1px solid black'>
        <div class=logintext style="width:100%;">
        	<br>
        	<p style="font-style: bold; font-size: 30px"> UPDATE THE CAR </p>
            <label for="text">Car ID:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="cid">
            <br>
            <br>
            <br>
            <div style="width:50%; float:left"
            <label for="text">Color:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="color">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="colorlog">
            <br>
            <br>
            <label for="text">Price:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="price">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="pricelog">
            <br>
            <br>
            <label for="text">Availability (1-yes 2-no):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="avail">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="availlog">
            <br>
            <br>
        	<br>
            </div>
            <div style="width:50%; float:left"
            <label for="text">Model:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="model">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="modellog">
            <br>
            <br>
            <label for="text">Gear-Type (1-auto 2-manual):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="gtype">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="gtypelog">
            <br>
            <br>
            <label for="text">Photo:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="photo">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="photolog">
            <br>
            <br>
        	<br>
        	</div>
        </div>
    </form>

    <form method=POST action='car_helper.php' align="center" style='width:33%; height: 70%; background-color:yellow;margin-top:1%; font-family:Georgia; float:left'>
        <div class=logintext style="width:100%; padding-top: 5%">
        	<br>
        	<p style="font-style: bold; font-size: 30px"> DELETE A CAR </p>
        	<br>
        	<br>
        	<br>
            <br><br>
            <br>
            <label for="text">Car ID:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="cid">
            <br>
            <br>
            <br>
            <br>
            <input style="width:80%; height:50px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="log3">
        </div>
    </form>


</body>


</html>