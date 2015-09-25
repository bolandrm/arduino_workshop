require "serialport"
require "twitter"
require 'dotenv'
require "sentimental"

Dotenv.load
Sentimental.load_defaults
Sentimental.threshold = 0.25
analyzer = Sentimental.new

#params for serial port
port_str = "/dev/tty.wchusbserial1410"  #may be different for you
baud_rate = 9600

sp = SerialPort.new(port_str, baud_rate)

client = Twitter::REST::Client.new do |config|
  config.consumer_key        = ENV["TCK"]
  config.consumer_secret     = ENV["TCS"]
  config.access_token        = ENV["TAT"]
  config.access_token_secret = ENV["TATS"]
end

#Thread.new do
#  loop do
#    read from arduino if you want
#    printf("%c", sp.getc)
#  end
#end

puts "hi"
puts "try: @justinxreese, @realDonaldTrump, @garybernhardt, @MileyCyrus"

loop do
  begin
    puts "Pick a user: "
    username = gets

    puts "you picked #{username}"
    tweets = client.user_timeline(username, include_rts: false).first(10)
    tweet_text = tweets.map(&:text).join(" ")

    sentiment = analyzer.get_sentiment(tweet_text)
    puts analyzer.get_score(tweet_text)
    puts sentiment

    if sentiment == :positive
      sp.write("0,255,0\n")
    elsif sentiment == :neutral
      sp.write("255,255,0\n")
    else
      sp.write("255,0,0\n")
    end

    puts
    puts
  rescue Twitter::Error::NotFound
    puts "not found"
  end
end

sp.close
