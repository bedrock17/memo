package main

import (
	"context"
	"fmt"
	"log"

	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

//동작하는 mongodb 샘플코드

//Phone : 임베딩된 구조체 테스트
type Phone struct {
	Os     string
	Name   string
	Number string
}

//Person : DB에 넣은 샘플 포맷
type Person struct {
	Name      string
	Age       int
	City      string
	Tmp       int64
	CellPhone Phone
}

func main() {

	clientOptions := options.Client().ApplyURI("mongodb://localhost:27017")
	client, err := mongo.Connect(context.TODO(), clientOptions)

	if err != nil {
		log.Fatal(err)
	}

	err = client.Ping(context.TODO(), nil)

	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Connected to MongoDB!")

	collection := client.Database("golangTest").Collection("golang")

	ruan := Person{Name: "Ruan", Age: 34, City: "Cape Town", Tmp: 10, CellPhone: Phone{Os: "IOS", Name: "S1", Number: "123-123-123"}}
	james := Person{Name: "James", Age: 32, City: "Nairobi", Tmp: 20, CellPhone: Phone{Os: "Android", Name: "S2", Number: "123-356-123"}}
	frankie := Person{Name: "Frankie", Age: 31, City: "Nairobi", Tmp: 30, CellPhone: Phone{Os: "Android", Name: "S3", Number: "123-222-123"}}

	trainers := []interface{}{ruan, james, frankie}

	insertManyResult, err := collection.InsertMany(context.TODO(), trainers)

	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Inserted multiple documents: ", insertManyResult.InsertedIDs)

	err = client.Disconnect(context.TODO())

	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Connection to MongoDB closed.")
}
