<?php
/**
 * @file solution.php
 * @author Mihail Croitor <mcroitor.gmail.com>
 * @brief `substring` task solution
 * @version 0.1
 */

$S = fgets(STDIN);
list($POS, $N) = explode(' ', trim(fgets(STDIN)));
if ($N > strlen($S) - $POS) {
    $N = strlen($S) - $POS;
}
$substring = substr($S, $POS, $N);
echo $substring;
