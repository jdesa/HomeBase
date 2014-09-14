function ajaxCall() {
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

    
$(document).keypress(function(e) {
  if(e.which == 13) {
      console.log("ENTER PRESSED");
      ajaxCall();
  }
});
    