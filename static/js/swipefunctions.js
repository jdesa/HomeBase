var container = $('.index'),
    scrollTo = $('#about');

function ajaxGet() {
    $.ajax({
  type: "GET",
  url: "/status",
//        // actual url /status
//        "https://graph.api.smartthings.com/api/smartapps/installations/44494efe-0369-4b8d-99c3-1cb935c344fa/switch",
  dataType: 'json',
//  data: {foo: "bar"},
  success: function (data){
      console.log(data);
      alert(data["value"]);
  }
});
}

function ajaxPut() {
    $.ajax({
  type: "PUT",
  url: "/control",
//        // actual url /status
//        "https://graph.api.smartthings.com/api/smartapps/installations/44494efe-0369-4b8d-99c3-1cb935c344fa/switch",
  dataType: 'json',
//  data: {foo: "bar"},
  success: function (data){
      console.log(data);
      alert(data["value"]);
  }
});
}

    
$(document).keypress(function(e) {
    console.log(e.which);
  if(e.which == 13) {
      console.log(e.which);
      console.log("ENTER PRESSED");
      ajaxGet();
  }
    if(e.which == 115) {
        console.log("s pressed");
        container.animate({
    scrollTop: scrollTo.offset().top - container.offset().top + container.scrollTop()
});
    }
});


function toggleLamp() {
    console.log("click!");
    var lamp = $("#lamp");
    if (lamp.hasClass("lamp_off")) {
        console.log("lamp off");
        lamp.removeClass("lamp_off");
        lamp.addClass("lamp_on");
        lamp.attr("src","../static/img/flamp%20on.png");
    }
    else {
        console.log("lamp on");
        lamp.addClass("lamp_off");
        lamp.removeClass("lamp_on");
        lamp.attr("src","../static/img/flamp%20off.png");
    }
}




