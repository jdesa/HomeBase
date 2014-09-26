from flask import Flask, render_template, jsonify
import requests
app = Flask(__name__)


@app.route("/")
def hello():
    return render_template('index.html')
'''
#checks the status of a smartthings device
@app.route("/status")
def status():
    r = requests.get("https://graph.api.smartthings.com/api/smartapps/installations/44494efe-0369-4b8d-99c3-1cb935c344fa/switch", auth=('ckskylight@gmail.com', 'Hamster111'))
    return jsonify(r.json()[0])

#controls a device
@app.route("/control", methods=['PUT'])
def control():
    print "Hamster1"

    r = requests.put("https://graph.api.smartthings.com/api/smartapps/installations/44494efe-0369-4b8d-99c3-1cb935c344fa/switch", {"value":"on"}, auth=('ckskylight@gmail.com', 'Hamster111'))
    print "Hamster Signal"
    print r
    print r.json()
    print "Hamster2"
    return "Hamster3"

'''
#return flask.jsonify(**f)

if __name__ == "__main__":
    app.debug = True
    app.run()
    