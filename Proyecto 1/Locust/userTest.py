import time

from locust import HttpUser, task

class userTest(HttpUser):
    @task
    def access_model(self):
        self.client.get("/prueba")
    
    def on_start(self):
        self.client.get("/userid")