function takeValue(){
    var labels = ["enter account number", "balance at beging", "\
    total item charged", "total of all credit applied", "allowed credit limit"];
    var storage = [0, 0, 0, 0, 0];
    for(var i=0; i<5; i++){
        storage[i] =parseInt(prompt(labels[i]));
    }
    var newBalance = storage[1]+storage[2]-storage[3];
    document.getElementById("status").innerHTML = newBalance;
}
var total = 0;
function collect(){
    var container = document.getElementById("table").innerHTML;
    //alert(container.length);
    container = container.slice(0, (container.length-21));
    //alert(container.length);
    var item = document.getElementById("item");
    var price = document.getElementById("price");
    total += parseFloat(price.value);
    container += "\n\
    <tr>\
    <td>"+ item.value+"</td>\
    <td>" + price.value + "</td>\
    </tr>";
    document.getElementById("table").innerHTML = container+"</tbody></tabel>";
    //alert(container);
}

function showEarning(){
    document.getElementById("earn").innerHTML = total*.09 + 200;
    total = 0;
}

function encrypt(){
    var data = parseInt(document.getElementById("data").value);
    if(data > 9999){
        alert("can encode only four digit code");
    }
    var num = "";
    while(data > 0){
        var digit = data%10;
        alert(digit);
        digit = (digit+7)%10;
        num += digit;
        data = parseInt(data/10);
    }
    document.getElementById("encrypted").value = num;
}