#pragma once

#include <stdexcept>
#include "Subscription.h"

namespace Asyncie {
    /**
     * Will receive call to {@link #onSubscribe(Subscription)} once after passing an instance of {@link Subscriber} to {@link Publisher#subscribe(Subscriber)}.
     * <p>
     * No further notifications will be received until {@link Subscription#request(long)} is called.
     * <p>
     * After signaling demand:
     * <ul>
     * <li>One or more invocations of {@link #onNext(Object)} up to the maximum number defined by {@link Subscription#request(long)}</li>
     * <li>Single invocation of {@link #onError(Throwable)} or {@link Subscriber#onComplete()} which signals a terminal state after which no further events will be sent.
     * </ul>
     * <p>
     * Demand can be signaled via {@link Subscription#request(long)} whenever the {@link Subscriber} instance is capable of handling more.
     *
     * @param <T> the type of element signaled.
     */
    template<typename T>
    struct Subscriber {
        /**
         * Invoked after calling {@link Publisher#subscribe(Subscriber)}.
         * <p>
         * No data will start flowing until {@link Subscription#request(long)} is invoked.
         * <p>
         * It is the responsibility of this {@link Subscriber} instance to call {@link Subscription#request(long)} whenever more data is wanted.
         * <p>
         * The {@link Publisher} will send notifications only in response to {@link Subscription#request(long)}.
         *
         * @param subscription {@link Subscription} that allows requesting data via {@link Subscription#request(long)}
         */
        virtual void onSubscribe(const Subscription &subscription) = 0;

        /**
         * Data notification sent by the {@link Publisher} in response to requests to {@link Subscription#request(long)}.
         *
         * @param element the element signaled
         */
        virtual void onNext(const T &element) = 0;

        /**
         * Failed terminal state.
         * <p>
         * No further events will be sent even if {@link Subscription#request(long)} is invoked again.
         *
         * @param throwable the throwable signaled
         */
        virtual void onError(const std::runtime_error &throwable) = 0;

        /**
         * Successful terminal state.
         * <p>
         * No further events will be sent even if {@link Subscription#request(long)} is invoked again.
         */
        virtual void onComplete() = 0;
    };
}