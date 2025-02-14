FROM alpine:3.19

WORKDIR /chall

RUN apk add --no-cache gcc musl-dev make

COPY ./src /chall

RUN make

EXPOSE 2025

# Command to run the server
CMD ["./main"]