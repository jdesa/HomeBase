from flask import Flask, render_template, jsonify
import requests
app = Flask(__name__)


@app.route("/")
def hello():
    return render_template('index.html')

@app.route("/status")
def status():
    r = requests.get("https://graph.api.smartthings.com/api/smartapps/installations/44494efe-0369-4b8d-99c3-1cb935c344fa/switch", auth=('ckskylight@gmail.com', 'Hamster111'))
    return jsonify(r.json()[0])

#return flask.jsonify(**f)

if __name__ == "__main__":
    app.debug = True
    app.run()
    