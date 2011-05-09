/*
 * satk - SIM application toolkit
 * Copyright © 2011, Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Written by - Luc Yriarte <luc.yriarte@linux.intel.com>
 */




function checkNumericChar(aChar)
{
    return (aChar >= '0' &&  aChar <= '9')
         || aChar == '*'
         || aChar == '#'
         || aChar == '+'
}

function checkNumericString(aString)
{
    for (var i=0; i<aString.length; i++)
        if (!checkNumericChar(aString.charAt(i)))
            return false;
    return true;
}

function checkString(aString, minChars, maxChars, isNumeric)
{
    if (minChars != -1 && aString.length < minChars)
        return false;
    if (maxChars != -1 && aString.length > maxChars)
        return false;
    if (isNumeric)
        return checkNumericString(aString);
    return true;
}
