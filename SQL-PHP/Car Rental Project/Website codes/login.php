<?php

error_reporting(E_ALL ^ E_DEPRECATED);
$link = mysqli_connect("localhost", "root", "", "carproject");


// Check connection
if($link === false){
    die("ERROR: Could not connect. " .mysqli_connect_error());
}


if(empty($_POST['adminid']) || empty($_POST['pass'])   )
{
  echo "<script>alert('You have an empty field.');</script>";

    header("Refresh:0; url=login.html");   // go back to the login page
}

if(isset($_POST['log']))
{
    $admin_id = mysql_real_escape_string($_POST['adminid']);     // to get rid of the tricky characters which can destroy the database.
    $password = md5(mysql_real_escape_string($_POST['pass']));  // turn into a hash function.
    $res= mysqli_query($link,"SELECT * FROM admin WHERE admin_id = '$admin_id' ");
   
    if($res === FALSE) {
      //die(mysql_error()); // TODO: better error handling
    }
    
    $admin=mysqli_fetch_array($res);
     
    if($admin == NULL)   // if there is no such user like that.
    {
      echo "<script>alert('The ID does not exist');</script>";
      header("Refresh:0; url=login.html");   // go back to the login page
    } 
    
    else if($admin['pass']!= $password || $admin['admin_id']!= $admin_id)
    {
      echo "<script>alert('The password or the username is incorrect');</script>";
      header("Refresh:0; url=login.html");
    }

    else if($admin['pass'] == $password && $admin['admin_id'] == $admin_id)
    {
      echo "<script>alert('You have succesfully entered the system !');</script>";
      header("Refresh:0; url=adminpage.html");
    }
    
    else{
      header("Refresh:0; url=login.html");
    }
}
