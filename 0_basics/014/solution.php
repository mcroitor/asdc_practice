
<?php



/*
 * @file solution.php
 * @author Grigoret Piotr
 * @brief `proxy` task solution
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

$c = $argv[1];

function isNumber($c){

    return is_numeric($c); 
}

$result = isNumber($c);
echo $result;


?>    
