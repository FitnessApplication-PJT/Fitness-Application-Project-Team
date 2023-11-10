 import speech_recognition as sr
import webbrowser
import os
import re


import wikipedia
import win32com.client as wincl

# ... (other imports and functions)

def say(text):
    speaker = wincl.Dispatch("SAPI.SpVoice")
    speaker.Speak(text)

def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language="en-in")
        print(f"User Said: {query}")
        return query.lower()
    except sr.UnknownValueError:
        print("Could not understand audio.")
        return ""
    except sr.RequestError as e:
        print("Could not request results; {0}".format(e))
        return ""

if __name__ == '__main__':
    print("Hello World")
    say("Hello, I am Assistant Jarvis. Created By You.")

    while True:
        say("Tell me your command")
        print("Tell me your command")
        text = takecommand()

        # Exit the loop and end the program
        if "end" in text:
            say("Ending this conversation. Goodbye!")
            break

        # Handle Wikipedia searches
        elif "wikipedia" in text:
            query = text.replace("wikipedia", "").strip()
            try:
                page = wikipedia.page(query)
                summary = wikipedia.summary(query, sentences=1)
                say(f"Here's a summary from Wikipedia: {summary}")
            except wikipedia.exceptions.DisambiguationError:
                say("Please provide more context for your search.")
            except wikipedia.exceptions.PageError:
                say("I couldn't find information on that topic on Wikipedia.")

        # Handle addition operations
        elif "add" in text:
            numbers = re.findall(r'\d+', text)
            if len(numbers) >= 2:
                num1 = int(numbers[0])
                num2 = int(numbers[1])
                result = num1 + num2
                say(f"The result of {num1} plus {num2} is {result}")
                print(f"The result of {num1} plus {num2} is {result}")
            else:
                say("I didn't find enough numbers to perform addition.")

        # Handle opening websites
        elif any(site in text for site in ["youtube", "google", "gmail", "rediffmail"]):
            for site in ["youtube", "google", "gmail", "rediffmail"]:
                if site in text:
                    say(f"Opening {site}")
                    webbrowser.open(f"https://www.{site}.com")
                    break

        # Search on Google
        elif "search" in text:
            query = text.replace("search", "").strip()
            for j in re.search(query, num=5, stop=5, pause=2):
                webbrowser.open(j)

        # Handle system commands
        elif "open" in text:
            app_name = text.replace("open", "").strip()
            if app_name == "notepad":
                os.system("notepad")
                say("Opening Notepad")
            elif app_name == "calculator":
                os.system("calc")
                say("Opening Calculator")
            else:
                say(f"Sorry, I don't know how to open {app_name}.")

        else:
            say("I'm sorry, I didn't understand that command. Can you please repeat?")

