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
		<div onclick = "location.href = ''" class="topbuttons" type="button" type="button" style="width:16.66%;border:0px;float:left;"> Tenant </div>
		<div onclick = "location.href = 'car.php'" class="topbuttons" type="button" type="button" style="width:16.66%;border:0px;float:left;"> Car </div>
	</div>

	<?php
	
		$result = mysqli_query($link,"SELECT * FROM tenant");
		echo "<table border='1px solid orange' style='width:100%; background-color: orange; text-align:center; font-family:Calibri; font-size:20px'>
		<tr>
		<th>Nationality ID</th>
		<th>Name</th>
		<th>Age</th>
		<th>IBAN</th>
		</tr>";

		while($row = mysqli_fetch_array($result))
		{
			echo "<tr>";
			echo "<td>" . $row['tid'] . "</td>";
			echo "<td>" . $row['tname'] . "</td>";
			echo "<td>" . $row['Age'] . "</td>";
			echo "<td>" . $row['tiban'] . "</td>";
			echo "</tr>";
		}
		echo "</table>";
	?>

	<form method=POST action='tenent_helper.php' align="center" style='width:33.3%; height: 70%; background-color:yellow;margin-top:1%; font-family:Georgia; float:left; border-right: 1px solid black'>
        <div class=logintext style="width:100%;">
        	<br>
        	<p style="font-style: bold; font-size: 30px"> INSERT A NEW TENANT </p>
        	<br>
        	<label for="text">Nationality ID (11 Digits):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tid">
            <br>
            <br>
            <label for="text">Name:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tname">
            <br>
            <br>
            <br>
            <label for="text">Age:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tage">
            <br>
            <br>
            <br>
            <label for="text">IBAN (24 Characters):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tableiban">
            <br>
            <br>
            <br>
            <br>
            <input style="width:80%; height:50px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="log1">
        </div>
    </form>

	<form method=POST action='tenent_helper.php' align="center" style='width:33.3%; height: 70%; background-color:yellow;margin-top:1%; font-family:Georgia; float:left; border-right: 1px solid black'>
        <div class=logintext style="width:100%; padding-top: 5%">
        	<p style="font-style: bold; font-size: 30px"> CHANGE A TENANT </p>
        	<label for="text">Nationality ID (11 Digits):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tid">
            <br>
            <br>
            <label for="text">Name:</label>
            <br>
            <br>
            <input style="width:80%; height:30px;" type="text" class="form-control" name="tname">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="namelog">
            <br>
            <br>
            <label for="text">Age:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tage">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="agelog">
            <br>
            <br>
            <label for="text">IBAN (24 Characters):</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tableiban">
            <br>
            <br>
            <input style="width:80%; height:30px; background-color: lightgray; 
            font-family: Georgia" id="buton" type="submit" 
            value= "Submit" / name="ibanlog">
        </div>
    </form>

    <form method=POST action='tenent_helper.php' align="center" style='width:33%; height: 70%; background-color:yellow;margin-top:1%; font-family:Georgia; float:left'>
        <div class=logintext style="width:100%; padding-top: 5%">
        	<br>
        	<p style="font-style: bold; font-size: 30px"> DELETE A TENANT </p>
        	<br>
        	<br>
        	<br>
            <br><br>
            <br>
            <label for="text">Nationality ID:</label>
            <br>
            <br>
            <input style="width:80%; height:30px" type="text" class="form-control" name="tid">
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


