#!/usr/bin/env python
import sys
from flask import Flask


app = Flask(__name__)
@app.route('/hello')
@app.route('/whatsup')

def hello():
    return 'Hello, world!' 

def whatsup():
    return 'You tell me!'
